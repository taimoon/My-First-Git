#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdlib.h>
#include<stdio.h>

#define stackClass(T)\
struct node{\
    T val;\
    struct node* next;\
};\
typedef struct node node;\
typedef struct node* nodePtr;\
int getLen(node *li);\
int isEmpty(node *li){return li == NULL;}\
void printNode(node *li);\
void push(node **li, T val);\
T pop(node **li);\
T top(node *li){return li->val;}\
\
void push(node **li, T val){\
    node *newNode = (node *)malloc(sizeof(struct node));\
    newNode->val = val;\
    newNode->next = *li;\
    *li = newNode;\
};\
T pop(node **li){\
    if((*li)==NULL)\
        return NULL;\
    T val = (*li)->val;\
    node *tempNode = *li;\
    *li = (*li)->next;\
    free(tempNode);\
    return val;\
};

#define printStack(printFunc)\
void printNode(node *li){\
    node *curr = li;\
    while(curr != NULL){\
        printFunc(curr->val);\
        printf(" ");\
        curr = curr->next;\
    }\
}



#endif // STACK_H_INCLUDED
