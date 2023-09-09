OBJS=f1.o f2.o
OBJS+=main.o
CFLAGS=-c -Wall -I include
test:$(OBJS)
	gcc $(OBJS) -o test
f1.o:f1.c
f2.o:f2.c
main.o:main.c
.PHONY:clean
clean:
	rm *.o test