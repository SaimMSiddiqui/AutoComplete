#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void replaceWordInSentence(char *sentence, const char *oldWord, const char *newWord) {
    char *position = strstr(sentence, oldWord);
    if (position) {
        memmove(position + strlen(newWord), position + strlen(oldWord), strlen(position + strlen(oldWord)) + 1);
        memcpy(position, newWord, strlen(newWord));
    }
}

int main(void) {
    
    struct TrieNode *root = createNode();
    
    FILE *dictionaryFile = fopen("words.txt", "r");
    if (dictionaryFile == NULL) {
        printf("ERROR: Dictionary file could not be opened.\n");
        return 1;
    }
    
    char word[100];
    while (fscanf(dictionaryFile, "%s", word) != EOF) {
        insert(root, word);
    }
    fclose(dictionaryFile);
    
    char sentence[500];
    printf("Enter a sentence with incomplete words: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        // Token contains a word from the sentence
        // Check if it's in the dictionary Trie
        if (!search(root, token)) {
            // Word not found in the dictionary, prompt the user for correction
            char correction[100];
            printf("Word not found in the dictionary. Enter a correction for '%s': ", token);
            scanf("%s", correction);
            // Replace the incomplete word with the correction in the sentence
            replaceWordInSentence(sentence, token, correction);
            // Set 'token' to the corrected word
            token = correction;
        }
        token = strtok(NULL, " ");
    }
    
    printf("Corrected sentence: %s\n", sentence);
    
    // Prompt for names and process them as needed
    char names[500]; // Adjust the array size as needed
    printf("Enter any names (separated by spaces): ");
    fgets(names, sizeof(names), stdin);
    
    char *nameToken = strtok(names, " ");
    while (nameToken != NULL) {
        // Process the name as needed, e.g., add it to a list
        printf("Name: %s\n", nameToken);
        nameToken = strtok(NULL, " ");
    }
    
    return 0;
}
