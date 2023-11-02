CROSS =
CC = $(CROSS)gcc
CXX = $(CROSS)g++
DEBUG = -g
CFLAGS = $(DEBUG) -Wall -c -fPIC
MV = mv -f
RM = rm -rf
LN = ln -sf

TARGET = libhello.so

TOP_PATH = $(shell pwd)
INC_PATH = $(TOP_PATH)/include
SRC_PATH = $(TOP_PATH)
SRC_PATH += $(TOP_PATH)/src
MOD_PATH = $(TOP_PATH)/modules
MOD_LIB_PATH = $(MOD_PATH)/lib
MOD_INC_PATH = $(MOD_PATH)/include
DIRS = $(shell find $(SRC_PATH) -maxdepth 3 -type d)
FILES = $(foreach dir, $(DIRS), $(wildcard $(dir)/*.cpp))

##########################################################
# modules
##########################################################
modules =
MODULES_PATH = $(foreach m, $(modules), $(MOD_PATH)/$(m))

##########################################################
# srcs
##########################################################
SRCS_CPP += $(foreach dir, $(DIRS), $(wildcard $(dir)/*.cpp))
SRCS_CC += $(foreach dir, $(DIRS), $(wildcard $(dir)/*.cc))
SRCS_C += $(foreach dir, $(DIRS), $(wildcard $(dir)/*.c))

##########################################################
# objs
##########################################################
OBJS_CPP = $(patsubst %.cpp, %.o, $(SRCS_CPP))
OBJS_CC = $(patsubst %.cc, %.o, $(SRCS_CC))
OBJS_C = $(patsubst %.c, %.o, $(SRCS_C))

##########################################################
# paths
##########################################################
INC_PATH += -I$(MOD_INC_PATH)
INC_PATH += -I$(MOD_PATH)
LIB_PATH += -L$(TOP_PATH)/lib
LIB_PATH += -L$(MOD_LIB_PATH)

##########################################################
# libs
##########################################################

##########################################################
# building
##########################################################
all:$(TARGET)

$(TARGET) : $(OBJS_CPP) $(OBJS_CC) $(OBJS_C)
    @ for i in $(MODULES_PATH); \
    do \
    make -C $$i; \
    done

    @ $(CXX) $^ -o $@ $(LIB_PATH) $(LIBS)
    @ echo Create $(TARGET) ok...

$(OBJS_CPP):%.o : %.cpp
    $(CXX) $(CFLAGS) $< -o $@ $(INC_PATH)

$(OBJS_CC):%.o : %.cc
    $(CXX) $(CFLAGS) $< -o $@ $(INC_PATH)

$(OBJS_C):%.o : %.c
    $(CXX) $(CFLAGS) $< -o $@ $(INC_PATH)

$(OBJS_C):%.o : %.c
    $(CC) $(CFLAGS) $< -o $@ $(INC_PATH)

.PHONY : clean
clean:
    @ $(RM) $(TARGET) $(OBJS_C)
