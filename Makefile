C = gcc
CFLAGS = -Wall -std=c99

SRC_DIR = src
TEST_DIR = test

all: main tests

main: $(SRC_DIR)/main.c $(SRC_DIR)/trie.c
	$(C) $(CFLAGS) -o main $(SRC_DIR)/main.c $(SRC_DIR)/trie.c

tests: $(TEST_DIR)/test_trie.c $(SRC_DIR)/trie.c
	$(C) $(CFLAGS) -o tests -I$(SRC_DIR) $(TEST_DIR)/test_trie.c $(SRC_DIR)/trie.c

clean:
	rm -f main tests