TARGET=list_test

#编译输出文件路径
BUILD_DIR=build
OBJ_DIR=$(BUILD_DIR)/obj
OUT_DIR=$(BUILD_DIR)/out

#设置删除指令
RM=rm -rf

#设置编译器
CC=gcc

#优化等级
OPT=-O0 -g

#C编译参数
C_FLAGS=-std=c99 -Wall $(OPT) -MMD -MP -fdiagnostics-color=always

#C全局宏定义
C_DEFINES:=
C_DEFINES:=$(addprefix -D, $(C_DEFINES))

#头文件路径
INCLUDE_DIRS=\
	list \
	test \

INCLUDE_FLAGS=$(addprefix -I, $(INCLUDE_DIRS))

#源文件
C_SRCS=\
	main.c \
	test/singly_list_test.c \
	test/doubly_list_test.c \
    list/singly_list.c \
    list/doubly_list.c \

OBJS=$(addprefix $(OBJ_DIR)/, $(notdir $(C_SRCS:.c=.o)))

vpath %.c $(dir $(C_SRCS))

all:$(OUT_DIR)/$(TARGET)

$(OUT_DIR)/$(TARGET):$(OBJS) Makefile | $(OUT_DIR)
	$(CC) $(OBJS) -o $@

$(OBJ_DIR)/%.o:%.c Makefile | $(OBJ_DIR)
	$(CC) -c $< $(C_DEFINES) $(INCLUDE_FLAGS) $(C_FLAGS) -o $@

$(OBJ_DIR):$(BUILD_DIR)
	mkdir -p $(OBJ_DIR)

$(OUT_DIR):$(BUILD_DIR)
	mkdir -p $(OUT_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

-include $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.d)))

.PHONY:clean print

clean:
	$(RM) $(OBJ_DIR)
	$(RM) $(OUT_DIR)

print:
	@echo OBJS = $(OBJS)
	@echo INCLUDE_DIRS = $(INCLUDE_DIRS)
	@echo INCLUDE_FLAGS = $(INCLUDE_FLAGS)