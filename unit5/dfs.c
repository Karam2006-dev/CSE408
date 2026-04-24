#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Trie node structure
typedef struct TrieNode {
    struct TrieNode* children[26];
    int isEndOfWord;
} TrieNode;

// Function to create a new trie node
TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Function to insert a string into the trie
void insert(TrieNode* root, const char* key) {
    TrieNode* node = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (node->children[index] == NULL) {
            node->children[index] = createNode();
        }
        node = node->children[index];
    }
    node->isEndOfWord = 1;
}

// Function to concatenate two strings using trie
// This function creates the concatenated string and inserts it into the trie
char* concatenateUsingTrie(TrieNode* root, const char* str1, const char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char* concatenated = (char*)malloc(len1 + len2 + 1);
    strcpy(concatenated, str1);
    strcat(concatenated, str2);
    insert(root, concatenated);
    return concatenated;
}

// DFS function to traverse the trie and print words
void dfs(TrieNode* node, char* buffer, int depth) {
    if (node->isEndOfWord) {
        buffer[depth] = '\0';
        printf("%s\n", buffer);
    }
    for (int i = 0; i < 26; i++) {
        if (node->children[i] != NULL) {
            buffer[depth] = 'a' + i;
            dfs(node->children[i], buffer, depth + 1);
        }
    }
}

int main() {
    TrieNode* root = createNode();
    const char* str1 = "hello";
    const char* str2 = "world";
    char* result = concatenateUsingTrie(root, str1, str2);
    printf("Concatenated string: %s\n", result);
    // Demonstrate DFS traversal
    char buffer[100];
    dfs(root, buffer, 0);
    free(result);
    // Free trie nodes omitted for brevity
    return 0;
}