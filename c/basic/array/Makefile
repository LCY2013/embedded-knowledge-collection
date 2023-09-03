CFLAGS=-c -Wall
OBJS=arr.o arr-func.o

.PHONY:arr
arr:$(OBJS)
	gcc $(OBJS) -o arr-exe.o

.PHONY:clean
clean:
	find ./ -name "*.o" -exec rm {} \;;
