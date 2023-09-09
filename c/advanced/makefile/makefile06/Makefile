CFLAGS=-c -Wall -I include
test:f1/f1.o f2/f2.o main/main.o
	gcc f1/f1.o f2/f2.o main/main.o -o test
f1/f1.o:f1/f1.c
	gcc $(CFLAGS) $^ -o $@
f2/f2.o:f2/f2.c
	gcc $(CFLAGS) $^ -o $@
main/main.o:main/main.c
	gcc $(CFLAGS) $^ -o $@
.PHONY:clean
clean:
	find ./ -name "*.o" -exec rm {} \;;rm test