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

bool search (struct TrieNode * root, const char *word){
    struct TrieNode *current = root;

    while(*word){
        int index = *word -'a';
        if(!current->children[index])
            return false;
        current = current->children[index];
        word++;
    }
    return current->isEndOfWord;
}



int main(){
    struct TrieNode *root = createNode();

    insert(root, "hello");
    insert(root, "world");
    insert(root,"Hi");
    insert(root, "trie");
    printf("Searching for 'hello': %s\n", search(root, "hello") ? "Found" : "Not Found");
    printf("Searching for 'world': %s\n", search(root, "world") ? "Found" : "Not Found");
    printf("Searching for 'her': %s\n", search(root, "her") ? "Found" : "Not Found");
    printf("Searching for 'hi': %s\n", search(root, "hi") ? "Found" : "Not Found");
    

}