CFLAGS=-c -Wall
INOUT_OBJS=inout.o inout-func.o

.PHONY:inout
inout:$(INOUT_OBJS)
	gcc $(INOUT_OBJS) -o inout.o

.PHONY:clean
clean:
	find ./ -name "*.o" -exec rm {} \;;
