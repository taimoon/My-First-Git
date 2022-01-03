#ifndef GENERIC_FORWARD_LIST2_H_INCLUDED
#define GENERIC_FORWARD_LIST2_H_INCLUDED

#include <stdlib.h>
#include<stdio.h>
typedef char T;
printFunc(T val){printf("%d ", val);}
printFuncEnd(){printf(" ");}
struct node{
    T val;//you may change the T type and change the datatype of the parameters of functions below accordingly
    struct node* next;
};
typedef struct node node;
typedef struct node* nodePtr;
typedef struct list{
    node *self;
    node *end;
    size_t len;
}list;
#define list_init {.self = NULL, .end = NULL, .len = 0}
int getLen(node *li); //optional but easy
node* createNode(T val);
node* getNode(node *li, int pos);
node* getEndNode(node *li); //optional but can be used in pushback
node* searchNode(node *li);
void printNode(node *li);
void pushFront(node **li, T val);
void pushFrontNode(node **li, node **newNode);
void pushBack(node **li, T val);
void pushBackNode(node **li, node **newNode);
T popFront(node **li);//you may change the T to void so that it doesn't return anything
T popBack(node **li);//you may change the T to void so that it doesn't return anything
void insertion(node **li, int pos, T val);
void insertNode(node **li, int pos, node **newNode);
void insertionAfter(node **li, int pos, T val); //optional
void deletion(node **li, int pos);
void swapNode(node **li, int pos1, int pos2);

int getLen(node *li){
    node *curr = li;
    int len = 0;
    while(curr != NULL){
        curr = curr->next;
        ++len;
    }
    return len;
}
node* createNode(T val){
    node *newNode = (node *)malloc(sizeof(struct node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
node* getNode(node *li, int pos){
    node *curr = li;
    if(pos < 0){
            printf("\nNo Negative Bound");
            exit(EXIT_FAILURE);
    }
    int i = 0;
    while(i < pos && !(curr == NULL)){
        curr = curr->next;
        ++i;
    }
    if(curr == NULL){
            printf("\nout of bound!");
            exit(EXIT_FAILURE);
    }
    return curr;
}
node* getEndNode(node *li){
    node *curr = li;
    while(curr->next != NULL)
        curr = curr->next;
    return curr;
};
void printNode(node *li){
    node *curr = li;
    while(curr != NULL){
        printFunc(curr->val);
        curr = curr->next;
    }
}
void pushFront(node **li, T val){
    node *newNode = createNode(val);
    pushFrontNode(li, &newNode);
};
void pushFrontNode(node **li, node **newNode){
    (*newNode)->next = *li;
    *li = *newNode;
};
void pushBack(node **li, T val){
    node *newNode = createNode(val);
    pushBackNode(li, &newNode);
};
void pushBackNode(node **li, node **newNode){
    (*newNode)->next = NULL;
    if(*li == NULL){
        *li = *newNode;
    }
    else{
        node *endNode = getEndNode(*li);
        endNode->next = *newNode;
    }
};
T popFront(node **li){
    if((*li)==NULL)
        return NULL;
    T val = (*li)->val;
    node *tempNode = *li;
    *li = (*li)->next;
    free(tempNode);
    return val;
};
T popBack(node **li){
    T val;
    if(*li == NULL)
        return NULL;
    else if((*li)->next == NULL){
        val = (*li)->val;
        free(*li);
        *li = NULL;
        return val;
    }
    else{
        node *newEnd, *currEnd;
        newEnd = *li;
        while(newEnd->next->next != NULL)
            newEnd = newEnd->next;
        currEnd = newEnd->next;
        val = currEnd->val;
        newEnd->next = NULL;
        free(currEnd);
        return val;
    }
};
void insertion(node **li, int pos, T val){
    if(*li == NULL){
        printf("\nInsertion on Empty List");
        exit(0);
    }
    else if(pos == 0)
        pushFront(li, val);
    else{
        node *prev = getNode(*li, pos-1);
        if(prev->next == NULL){
            printf("\nout of bound!");
            exit(EXIT_FAILURE);
        }
        node *newNode = (node *)malloc(sizeof(struct node));
        newNode->val = val;
        newNode->next = prev->next;
        prev->next = newNode;
    }
};
void insertNode(node **li, int pos, node **newNode){
    if(*li == NULL){
        printf("\nInsertion on Empty List");
        exit(0);
    }
    else if(pos == 0)
        pushFrontNode(li, newNode);
    else{
        node *prev = getNode(*li, pos-1);
        if(prev->next == NULL){
            printf("\nout of bound!");
            exit(EXIT_FAILURE);
        }
        (*newNode)->next = prev->next;
        prev->next = (*newNode);
    }
};
void insertionAfter(node **li, int pos, T val){
    if(*li == NULL){
        printf("\nInsertion on Empty List");
        exit(EXIT_FAILURE);
    }
    else{
        node *curr = getNode(*li, pos);
        node *newNode = (node *)malloc(sizeof(struct node));
        newNode->val = val;
        if(curr->next == NULL){
            newNode->next = NULL;
        }
        else{
            newNode->next = curr->next;
        }
        curr->next = newNode;
    }
};
void deletion(node **li, int pos){
    if(*li == NULL){
        printf("\nDeletion on Empty List");
        exit(EXIT_FAILURE);
    }
    else if(pos == 0)
        popFront(li);
    else{
        node *prev = getNode(*li, pos-1);
        if(prev->next == NULL){
            printf("\nOut of bound!");
            exit(EXIT_FAILURE);
        }
        node *curr = prev->next;
        prev->next = curr->next;
        free(curr);
    }
};


#endif // GENERIC_FORWARD_LIST2_H_INCLUDED
