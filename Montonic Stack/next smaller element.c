#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;
void initStack(Stack* s) {
    s->top = -1;
}
int isFull(Stack* s) {
    return s->top == MAX - 1;
}
int isEmpty(Stack* s) {
    return s->top == -1;
}
void push(Stack* s, int value) {
    if (!isFull(s)) {
        s->arr[++(s->top)] = value;
    }
}
int pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->arr[(s->top)--];
    }
    return -1; // Indicate stack is empty
}
int peek(Stack* s) {
    if (!isEmpty(s)) {
        return s->arr[s->top];
    }
    return -1; // Indicate stack is empty
}
void nextSmallerElement(int* arr, int n, int* result) {
    Stack s;
    initStack(&s);
    for (int i = n - 1; i >= 0; i--) {
        while (!isEmpty(&s) && peek(&s) >= arr[i]) {
            pop(&s);
        }
        if (isEmpty(&s)) {
            result[i] = -1;
        } else {
            result[i] = peek(&s);
        }
        push(&s, arr[i]);
    }
}
int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int* result = (int*)malloc(n * sizeof(int));
    nextSmallerElement(arr, n, result);
    printf("Next smaller elements are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}