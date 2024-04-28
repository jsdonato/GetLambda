CC = g++
CFLAGS = -std=c++11 -O3
TESTS = $(wildcard test/*.cpp)
SRCS = $(wildcard src/*.cpp)
DEPS = $(wildcard src/*.hpp)
OBJS = $(patsubst src/%.cpp, %.o, $(SRCS))

%.o: src/%.cpp
	$(CC) $(CFLAGS) -I$(GMP_DIR)/include -c -o $@ $<

test: $(OBJS)
	$(CC) $(CFLAGS) -I$(GMP_DIR)/include -L$(GMP_DIR)/lib $(OBJS) $(TESTS) -o test/tests -lgmp
	./test/tests

clean:
	rm -f *.o
