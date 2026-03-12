CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -g


SRC_DIR = src
OBJ_DIR = obj
BIN_NAME = program

SRCS = $(wildcard $(SRC_DIR)/*.c)

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))


all: $(OBJ_DIR) $(BIN_NAME)


$(BIN_NAME): $(OBJS)
	$(CC) $(OBJS) -o $(BIN_NAME)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(BIN_NAME)
	rm -f input_simple.txt input_edge.txt

.PHONY: all clean

