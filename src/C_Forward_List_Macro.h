#ifndef C_FORWARD_LIST_MACRO_H_INCLUDED
#define C_FORWARD_LIST_MACRO_H_INCLUDED
#include <stdlib.h>
#include<stdio.h>
//#include"C_Forward_List_Macro.h"
//listCLass(char);
//printFunc(char val){printf("%d", val);}
//printList(printFunc);
#define listCLass(T)\
struct node{\
    T val;\
    struct node* next;\
};\
typedef struct node node;\
typedef struct node* nodePtr;\
int getLen(node *li);\
node* getNode(node *li, int pos);\
node* getEndNode(node *li);\
void printNode(node *li);\
void pushFront(node **li, T val);\
void pushBack(node **li, T val);\
T popFront(node **li);\
T popBack(node **li);\
void insertion(node **li, int pos, T val);\
void insertionAfter(node **li, int pos, T val);\
void deletion(node **li, int pos);\
\
int getLen(node *li){\
    node *curr = li;\
    int len = 0;\
    while(curr != NULL){\
        curr = curr->next;\
        ++len;\
    }\
    return len;\
}\
node* getNode(node *li, int pos){\
    node *curr = li;\
    if(pos < 0){\
            printf("\nNo Negative Bound");\
            exit(EXIT_FAILURE);\
    }\
    int i = 0;\
    while(i < pos && !(curr == NULL)){\
        curr = curr->next;\
        ++i;\
    }\
    if(curr == NULL){\
            printf("\nout of bound!");\
            exit(EXIT_FAILURE);\
    }\
    return curr;\
}\
node* getEndNode(node *li){\
    node *curr = li;\
    while(curr->next != NULL)\
        curr = curr->next;\
    return curr;\
};\
void pushFront(node **li, T val){\
    node *newNode = (node *)malloc(sizeof(struct node));\
    newNode->val = val;\
    newNode->next = *li;\
    *li = newNode;\
};\
void pushBack(node **li, T val){\
    node *newNode = (node *)malloc(sizeof(struct node));\
    newNode->val = val;\
    newNode->next = NULL;\
    if(*li == NULL){\
        *li = newNode;\
    }\
    else{\
        node *endNode = getEndNode(*li);\
        endNode->next = newNode;\
    }\
};\
T popFront(node **li){\
    if((*li)==NULL)\
        return NULL;\
    T val = (*li)->val;\
    node *tempNode = *li;\
    *li = (*li)->next;\
    free(tempNode);\
    return val;\
};\
T popBack(node **li){\
    T val;\
    if(*li == NULL)\
        return NULL;\
    else if((*li)->next == NULL){\
        val = (*li)->val;\
        free(*li);\
        *li = NULL;\
        return val;\
    }\
    else{\
        node *newEnd, *currEnd;\
        newEnd = *li;\
        while(newEnd->next->next != NULL)\
            newEnd = newEnd->next;\
        currEnd = newEnd->next;\
        val = currEnd->val;\
        newEnd->next = NULL;\
        free(currEnd);\
        return val;\
    }\
};\
void insertion(node **li, int pos, T val){\
    if(*li == NULL){\
        printf("\nInsertion on Empty List");\
        exit(0);\
    }\
    else if(pos == 0)\
        pushFront(li, val);\
    else{\
        node *prev = getNode(*li, pos-1);\
        if(prev->next == NULL){\
            printf("\nout of bound!");\
            exit(EXIT_FAILURE);\
        }\
        node *newNode = (node *)malloc(sizeof(struct node));\
        newNode->val = val;\
        newNode->next = prev->next;\
        prev->next = newNode;\
    }\
};\
void insertionAfter(node **li, int pos, T val){\
    if(*li == NULL){\
        printf("\nInsertion on Empty List");\
        exit(EXIT_FAILURE);\
    }\
    else{\
        node *curr = getNode(*li, pos);\
        node *newNode = (node *)malloc(sizeof(struct node));\
        newNode->val = val;\
        if(curr->next == NULL){\
            newNode->next = NULL;\
        }\
        else{\
            newNode->next = curr->next;\
        }\
        curr->next = newNode;\
    }\
};\
void deletion(node **li, int pos){\
    if(*li == NULL){\
        printf("\nDeletion on Empty List");\
        exit(EXIT_FAILURE);\
    }\
    else if(pos == 0)\
        popFront(li);\
    else{\
        node *prev = getNode(*li, pos-1);\
        if(prev->next == NULL){\
            printf("\nOut of bound!");\
            exit(EXIT_FAILURE);\
        }\
        node *curr = prev->next;\
        prev->next = curr->next;\
        free(curr);\
    }\
};

#define printList(printFunc)\
void printNode(node *li){\
    node *curr = li;\
    while(curr != NULL){\
        printFunc(curr->val);\
        printf(" ");\
        curr = curr->next;\
    }\
}


#endif // C_FORWARD_LIST_MACRO_H_INCLUDED
