# Makefile ends here

#CROSS_COMPILE = arm-linux-gnu-

CC = $(CROSS_COMPILE)gcc

ifdef CROSS_COMPILE
TARGET = ./
endif


#DEBUG = -g -O0 -Wall
DEBUG = -g -O2
CFLAGS += $(DEBUG)

PROGS = ${patsubst %.c, %, ${wildcard *.c}}


all : $(PROGS)

install: $(PROGS)
ifdef CROSS_COMPILE
	mkdir $(TARGET)/run -p
	cp $(PROGS) $(TARGET)/run -f
endif
%.o : %.c
	$(CC)  $(CFLAGS) -c $< -o $@

.PHONY: uninstall clean print

uninstall :
ifdef CROSS_COMPILE
	cd $(TARGET)/run && rm -f $(PROGS)
endif
	rm -f $(PROGS)

clean : uninstall
	- rm -f $(PROGS)

print:
	@echo $(PROGS)
	@echo $(CC)
	@echo $(CFLAGS)

