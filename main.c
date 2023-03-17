#include "trie.h"
#include <stdio.h>

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
