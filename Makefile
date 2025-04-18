CC = g++
CFLAGS = -std=c++11 -O3
ROOT = $(shell pwd)
TESTS = $(wildcard test/*.cpp)
SRCS = $(wildcard src/*.cpp)
DEPS = $(wildcard src/*.hpp)
OBJS = $(patsubst src/%.cpp, %.o, $(SRCS))

GMP_DIR=$(shell sed -n '1p' $(ROOT)/build_cache)
PREFIX=$(shell sed -n '2p' $(ROOT)/build_cache)

%.o: src/%.cpp
	$(CC) $(CFLAGS) -I$(GMP_DIR)/include -c -o $@ $<

libgetlambda.a: $(OBJS)
	mkdir $(PREFIX)/lib
	mkdir $(PREFIX)/include
	ar rcs libgetlambda.a $(OBJS)
	mv libgetlambda.a $(PREFIX)/lib
	cp $(ROOT)/src/*hpp $(PREFIX)/include
	rm $(OBJS)

.PHONY: test
test:
	mkdir -p $(PREFIX)/test
	$(CC) $(CFLAGS) $(TESTS) -o $(PREFIX)/test/tests -I$(PREFIX)/include -L$(PREFIX)/lib -lgetlambda -I$(GMP_DIR)/include -L$(GMP_DIR)/lib -lgmp
	$(PREFIX)/test/tests

clean:
	rm -f *.o
	rm -rf $(PREFIX)/include
	rm -rf $(PREFIX)/lib
	rm -rf $(PREFIX)/test
