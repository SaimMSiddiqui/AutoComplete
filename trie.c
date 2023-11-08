//
//  trie.c
//  AutoComplete
//
//  Created by Saim Siddiqui on 3/17/23.
//

#include "trie.h"
#include <stdio.h>
#include <stdlib.h>

struct TrieNode *createNode(void);//private method

void printWords(struct TrieNode *node, char prefix[]) {
    if (node->isEndOfWord) {
        printf("%s\n", prefix);
    }
    for (int i = 0; i < 26; i++) {
        if (node->children[i] != NULL) {
            char c = 'a' + i;
            char word[100];
            sprintf(word, "%s%c", prefix, c);
            printWords(node->children[i], word);
        }
    }
}

bool search(struct TrieNode *root, const char *prefix) {
    struct TrieNode *node = root;
    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';
        if (node->children[index] == NULL) {
            return false;
        }
        node = node->children[index];
    }
    //printWords(node, prefix);
    return node-> isEndOfWord;
}

void insert(struct TrieNode *root, const char *word) {
    struct TrieNode *node = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (node->children[index] == NULL) {
            node->children[index] = createNode();
        }
        node = node->children[index];
    }
    node->isEndOfWord = true;
}

struct TrieNode *createNode(void) {
    struct TrieNode *node = (struct TrieNode *) malloc(sizeof(struct TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}
