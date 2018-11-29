# Andy Sayler
# CI Practice
# Summer 2014

CC = gcc
CFLAGS = -c -g -Wall -Wextra
LFLAGS = -g -Wall -Wextra

PKG_MATH_LIBS = -lm
PKG_CHECK_LIBS = `pkg-config --libs check`

.PHONY: all dep clean

all: geometry_test

geometry_test: geometry_test.o geometry.o
	$(CC) $(LFLAGS) $^ $(PKG_CHECK_LIBS) $(PKG_MATH_LIBS) -o $@

geometry_test.o: geometry_test.c geometry.h
	$(CC) $(CFLAGS) $< -o $@

geometry.o: geometry.c geometry.h
	$(CC) $(CFLAGS) $< -o $@

test: geometry_test
	./geometry_test
dep:
	sudo apt-get update
	sudo apt-get install check

clean:
	$(RM) *.o
	$(RM) geometry_test
	$(RM) *~
