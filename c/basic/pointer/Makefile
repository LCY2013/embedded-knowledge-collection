CFLAGS=-c -Wall
OBJS=ptr.o ptr-func.o

.PHONY:ptr
ptr:$(OBJS)
	gcc $(OBJS) -o ptr-exe.o

.PHONY:clean
clean:
	find ./ -name "*.o" -exec rm {} \;;
