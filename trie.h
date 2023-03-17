//
//  trie.h
//  AutoComplete
//
//  Created by Saim Siddiqui on 3/17/23.
//

#ifndef trie_h
#define trie_h

#include <stdbool.h>

struct TrieNode {
    bool isEndOfWord;
    struct TrieNode *children[26];
};

struct TrieNode *createNode(void);
void insert(struct TrieNode *root, const char *word);
void search(struct TrieNode *root, const char *prefix);
void printWords(struct TrieNode *node, char prefix[]);

#endif /* trie_h */
