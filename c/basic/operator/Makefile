CFLAGS=-c -Wall
BIT_OBJS=bit.o bit-func.o

.PHONY:bit
bit:$(BIT_OBJS)
	gcc $(BIT_OBJS) -o bit.o

.PHONY:clean
clean:
	find ./ -name "*.o" -exec rm {} \;;
