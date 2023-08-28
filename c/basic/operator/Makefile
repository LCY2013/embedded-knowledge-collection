CFLAGS=-c -Wall
BIT_OBJS=bit.o bit-func.o
OP_OBJS=operator.o operator-func.o

.PHONY:bit
bit:$(BIT_OBJS)
	gcc $(BIT_OBJS) -o bit.o

.PHONY:operator
operator:$(OP_OBJS)
	gcc $(OP_OBJS) -o operator.o

.PHONY:clean
clean:
	find ./ -name "*.o" -exec rm {} \;;
