CFLAGS=-c -Wall
OBJS=c.o c-func.o
LOOP_OBJS=loop.o loop-func.o
SWITCH_OBJS=switch.o switch-func.o

.PHONY:c
c:$(OBJS)
	gcc $(OBJS) -o c-exe.o

.PHONY:loop
loop:$(LOOP_OBJS)
	gcc $(LOOP_OBJS) -o loop-exe.o

.PHONY:switch
switch:$(SWITCH_OBJS)
	gcc $(SWITCH_OBJS) -o switch-exe.o

.PHONY:clean
clean:
	find ./ -name "*.o" -exec rm {} \;;
