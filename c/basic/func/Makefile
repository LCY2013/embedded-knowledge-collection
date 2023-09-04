CFLAGS=-c -Wall
OBJS=func.o func-func.o
P_OBJS=pfunc.o pfunc-func.o

.PHONY:func
func:$(OBJS)
	gcc $(OBJS) -o func-exe.o

.PHONY:pfunc
pfunc:$(P_OBJS)
	gcc $(P_OBJS) -o pfunc-exe.o

.PHONY:clean
clean:
	find ./ -name "*.o" -exec rm {} \;;
