CC = g++
CFLAGS = -std=c++11 -O3
ROOT = $(shell pwd)
TESTS = $(wildcard test/*.cpp)
SRCS = $(wildcard src/*.cpp)
DEPS = $(wildcard src/*.hpp)
OBJS = $(patsubst src/%.cpp, %.o, $(SRCS))

%.o: src/%.cpp
ifndef GMP_DIR
	@echo "Error: GMP_DIR not defined"
	exit 1
endif
	$(CC) $(CFLAGS) -I$(GMP_DIR)/include -c -o $@ $<

libgetlambda.a: $(OBJS)
	ar rcs libgetlambda.a $(OBJS)
	rm $(OBJS)
	$(CC) $(CFLAGS) $(TESTS) -o test/tests -I$(ROOT)/src -L$(ROOT) -lgetlambda -I$(GMP_DIR)/include -L$(GMP_DIR)/lib -lgmp

.PHONY: test
test:
	./test/tests

clean:
	rm -f libgetlambda.a
	rm -f test/tests
