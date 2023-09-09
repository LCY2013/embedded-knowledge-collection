CFLAGS=-c -Wall -I include
test:f1/f1.o f2/f2.o main/main.o
	gcc f1/f1.o f2/f2.o main/main.o -o test
.PHONY:clean
clean:
	find ./ -name "*.o" -exec rm {} \;;rm test