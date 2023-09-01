CFLAGS=-c -Wall
OBJS=c.o c-func.o

.PHONY:c
c:$(OBJS)
	gcc $(OBJS) -o c.o

.PHONY:clean
clean:
	find ./ -name "*.o" -exec rm {} \;;
