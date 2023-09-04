CFLAGS=-c -Wall
OBJS=func.o func-func.o

.PHONY:func
func:$(OBJS)
	gcc $(OBJS) -o func-exe.o

.PHONY:clean
clean:
	find ./ -name "*.o" -exec rm {} \;;
