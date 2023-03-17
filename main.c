#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TrieNode {
    bool isEndOfWord;
    struct TrieNode *children[26];
};

struct TrieNode *createNode(void);

void insert(struct TrieNode *root, const char *word);

void search(struct TrieNode *root, const char *prefix);

void printWords(struct TrieNode *node, char prefix[]);


int main() {
    char words[][100] = {"apple", "application", "banana", "book", "computer", "data", "dog", "door", "drive", "dust", "eagle", "earth", "eat", "egg", "elephant", "energy", "envelope", "erase", "exact", "exercise", "exit", "eye", "face", "factory", "fair", "family", "fan", "farm", "fast", "father", "fear", "feather", "feed", "feel", "feet", "female", "fence", "few", "field", "fight", "figure", "file", "fill", "film", "find", "finger", "fire", "first", "fish", "fix", "flag", "flame", "flat", "flight", "floor", "flower", "fly", "fold", "food", "foot", "force", "forest", "forget", "fork", "form", "fox", "frame", "free", "fresh", "friend", "frog", "front", "fruit", "fuel", "fun", "future", "game", "garden", "gas", "gate", "gather", "gear", "general", "gentle", "get", "gift", "girl", "give", "glass", "glove", "goat", "gold", "good", "government", "grass", "great", "green", "grey", "ground", "group", "grow", "guard", "guess", "guide", "gun", "hair", "hammer", "hand"};
        struct TrieNode *root = createNode();
        for (int i = 0; i < sizeof(words) / sizeof(words[0]); i++) {
            insert(root, words[i]);
        }

        char prefix[100];
        printf("Enter prefix: ");
        scanf("%s", prefix);
        printf("Autocomplete suggestions:\n");
        search(root, prefix);

        return 0;
    }

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

void search(struct TrieNode *root, const char *prefix) {
    struct TrieNode *node = root;
    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';
        if (node->children[index] == NULL) {
            return;
        }
        node = node->children[index];
    }
    printWords(node, prefix);
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
