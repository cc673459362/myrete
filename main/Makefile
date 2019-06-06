CC=g++
ROOT_DIR= ~/Downloads/drools/myrete
DEBUG ?=0
INCLUDE += -I $(ROOT_DIR)/alphamemory/
INCLUDE += -I $(ROOT_DIR)/alphanode/
INCLUDE += -I $(ROOT_DIR)/betamemory/
INCLUDE += -I $(ROOT_DIR)/compilenet/
INCLUDE += -I $(ROOT_DIR)/condition/
INCLUDE += -I $(ROOT_DIR)/joinnode/
INCLUDE += -I $(ROOT_DIR)/main/
INCLUDE += -I $(ROOT_DIR)/retenode/
INCLUDE += -I $(ROOT_DIR)/rule/
INCLUDE += -I $(ROOT_DIR)/terminalnode/
INCLUDE += -I $(ROOT_DIR)/token/
INCLUDE += -I $(ROOT_DIR)/WME/
INCLUDE += -I $(ROOT_DIR)/workingmemory/
INCLUDE += -I $(ROOT_DIR)/terminalnode/
INCLUDE += -I $(ROOT_DIR)/rule/

SRC += $(ROOT_DIR)/rule/rule.c
SRC += $(ROOT_DIR)/main/main.c
SRC += $(ROOT_DIR)/alphamemory/alphamemory.c
SRC += $(ROOT_DIR)/alphanode/alphanode.c
SRC += $(ROOT_DIR)/betamemory/betamemory.c
SRC += $(ROOT_DIR)/compilenet/addproduction.c
SRC += $(ROOT_DIR)/condition/condition.c
SRC += $(ROOT_DIR)/joinnode/joinnode.c
SRC += $(ROOT_DIR)/retenode/retenode.c
SRC += $(ROOT_DIR)/terminalnode/terminalnode.c
SRC += $(ROOT_DIR)/token/token.c
SRC += $(ROOT_DIR)/WME/myWME.c
SRC += $(ROOT_DIR)/workingmemory/workingmemory.c


CFLAGS =
ifeq ($(DEBUG),1)
	CFLAGS+= -g -O0
endif
OBJ = $(patsubst %.c,%.o,$(SRC))
TARGET := main

all:$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) -o $(TARGET) 
$(OBJ): %.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
clean:
	rm -rf $(OBJ)
