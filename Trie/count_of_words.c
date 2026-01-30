#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ALPHABET_SIZE 26

struct TrieNode{
    struct TrieNode * children[ALPHABET_SIZE];
    bool isEndOfWord;

};

struct TrieNode *createNode(){
    struct TrieNode *node = (struct TrieNode *) malloc(sizeof(struct TrieNode));

    node->isEndOfWord = false;

    for(int i =0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;


return node;

};

void insert(struct TrieNode *root, const char *word){
    struct TrieNode *current = root;
    while(*word){
        int index = *word - 'a';
        if(!current -> children[index])
            current->children[index] = createNode();
            current = current->children[index];
        word++;
    }

    current->isEndOfWord= true;
}
int countWords(struct TrieNode *root){
    if(root == NULL)
        return 0;

    int count = 0;

    if(root->isEndOfWord)
        count++;

    for(int i =0; i < ALPHABET_SIZE; i++){
        count += countWords(root->children[i]);
    }

    return count;
}
// longest prefix function
void longestPrefix(struct TrieNode *root, char *prefix, int level, char *result){
    if(root == NULL)
        return;

    if(root->isEndOfWord){
        prefix[level] = '\0';
        if(strlen(prefix) > strlen(result)){
            strcpy(result, prefix);
        }
    }

    for(int i =0; i < ALPHABET_SIZE; i++){
        if(root->children[i]){
            prefix[level] = 'a' + i;
            longestPrefix(root->children[i], prefix, level + 1, result);
        }
    }
}
int main(){
    struct TrieNode *root = createNode();

    insert(root, "hello");
    insert(root, "world");
    insert(root,"hi");
    insert(root, "trie");

    int totalWords = countWords(root);
    printf("Total words in Trie: %d\n", totalWords);
    char prefix[100];
    char result[100] = "";
    longestPrefix(root, prefix, 0, result);
    printf("Longest prefix in Trie: %s\n", result);
    

    return 0;
}