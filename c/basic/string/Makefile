CFLAGS=-c -Wall
OBJS=str.o str-func.o

.PHONY:str
str:$(OBJS)
	gcc $(OBJS) -o str-exe.o

.PHONY:clean
clean:
	find ./ -name "*.o" -exec rm {} \;;
