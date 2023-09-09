CFLAGS=-c -Wall -I include
VPATH=f1 f2 main
test:f1.o f2.o main.o
	gcc *.o -o test
.PHONY:clean
clean:
	find ./ -name "*.o" -exec rm {} \;;rm test