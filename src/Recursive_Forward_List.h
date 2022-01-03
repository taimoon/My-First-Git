#ifndef RECURSIVE_FORWARD_LIST_H_INCLUDED
#define RECURSIVE_FORWARD_LIST_H_INCLUDED

#include <stdlib.h>
#include<stdio.h>
///customise your datatype here
typedef char T;
printFunc(T val){printf("%d ", val);}
printFuncEnd(){printf(" ");}
//end of customise
struct node{
    T val;//you may change the T type and change the datatype of the parameters of functions below accordingly
    struct node* next;
};
typedef struct node node;
typedef struct node* nodePtr;
int getLen(node *li); //optional but easy
node* createNode(T val);
node* getNode(node *li, int pos);
node* getEndNode(node *li); //optional but can be used in pushback
node* searchNode(node *li);
void printNode(node *li);
void printNodeBack(node *li);
void pushFront(node **li, T val);
node* pushFrontNode(node *li, node *newNode);
void pushBack(node **li, T val);
node* pushBackNode(node *li, node *newNode);
T popFront(node **li);//you may change the T to void so that it doesn't return anything
T popBack(node **li);//you may change the T to void so that it doesn't return anything
void insertion(node **li, int pos, T val);
void insertNode(node **li, int pos, node **newNode);
void insertionAfter(node **li, int pos, T val); //optional
void deletion(node **li, int pos);

int getLen(node *li){
    if(li != NULL)
        return getLen(li->next)+1;
}
node* createNode(T val){
    node *newNode = (node *)malloc(sizeof(struct node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
node* getNode(node *li, int pos){
    if(li == NULL)
        exit(EXIT_FAILURE);
    else if(pos > 0)
        return getNode(li->next, pos-1);
    else
        return li;
}
node* getEndNode(node *li){
    if(li->next != NULL)
        return getEndNode(li->next);
    else
        return li;
};
void printNode(node *li){
    if(li != NULL){
        printFunc(li->val);
        printNode(li->next);
    }
}
void printNodeBack(node *li){
    if(li != NULL){
        printNodeBack(li->next);
        printFunc(li->val);
    }
}
void pushFront(node **li, T val){
    node *newNode = createNode(val);
    *li = pushFrontNode(*li, newNode);
};
node* pushFrontNode(node *li, node *newNode){
    newNode->next = li;
    return newNode;
};
void pushBack(node **li, T val){
    node *newNode = createNode(val);
    *li = pushBackNode(*li, newNode);
};
node* pushBackNode(node *li, node *newNode){
    if(li != NULL)
        li->next = pushBackNode(li->next, newNode);
    else
        return newNode;
    return li;
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
    else
            return popBack(&((*li)->next));
};
void insertion(node **li, int pos, T val){
    if(*li == NULL){
        printf("\nInsertion on Empty List");
        exit(0);
    }
    else if(pos == 0)
        pushFront(li, val);
    else
        insertion(&((*li)->next), pos-1, val);
};
void insertNode(node **li, int pos, node **newNode){
    if(*li == NULL){
        printf("\nInsertion on Empty List");
        exit(0);
    }
    else if(pos == 0)
        *li = pushFrontNode(*li, *newNode);
    else
        insertNode(&((*li)->next), pos-1, newNode);
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
    else
        deletion(&((*li)->next), pos-1);
};
#endif // RECURSIVE_FORWARD_LIST_H_INCLUDED
