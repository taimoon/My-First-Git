#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdlib.h>
#include<stdio.h>
typedef float T;
void printFunc(T val){
    printf("%.2f", val);
}
struct node{
    T val;//you may change the char type and change the parameter of functions below accordingly
    struct node* next;
    struct node* back;
};
typedef struct node node;
typedef struct node* nodePtr;
int getLen(node *li); //optional but easy
node* getNode(node *li, int pos);
node* getEndNode(node *li);
void printNode(node *li);
void printNodeBack(node *li);
void pushFront(node **li, T val);
void pushBack(node **li, T val);
T popFront(node **li);//you may change the char to void so that it doesn't return anything
T popBack(node **li);//you may change the char to void so that it doesn't return anything
void insertion(node **li, int pos, T val);
void insertionAfter(node **li, int pos, T val); //optional
void deletion(node **li, int pos);


int getLen(node *li){
    node *curr = li;
    int len = 0;
    while(curr != NULL){
        curr = curr->next;
        ++len;
    }
    return len;
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
    if(li == NULL)
        return NULL;
    node *curr = li;
    while(curr->next != NULL)
        curr = curr->next;
    return curr;
};
void printNodeRecur(node *li){
    if(li != NULL){
        printFunc(li->val);printf(" ");
        printNodeRecur(li->next);
    }
}
void printNodeBackRecur(node *li){
    if(li != NULL){
        printNodeBackRecur(li->next);
        printFunc(li->val);printf(" ");
    }
}
void printNode(node *li){
    node *curr = li;
    while(curr != NULL){
        printFunc(curr->val);printf(" ");
        curr = curr->next;
    }
}
void printNodeBack(node *li){
    node *curr = getEndNode(li);
    while(curr != NULL){
        printFunc(curr->val);printf(" ");
        curr = curr->back;
    }
}
void pushFront(node **li, T val){
    node *newNode = (node *)malloc(sizeof(struct node));
    newNode->val = val;
    newNode->next = *li;
    newNode->back = NULL;
    if(*li != NULL)
        (*li)->back = newNode;
    *li = newNode;
}
void pushBack(node **li, T val){
    if(*li == NULL)
        pushFront(li, val);
    else{
        node *newNode = (node *)malloc(sizeof(struct node));
        newNode->val = val;
        node *currEnd = getEndNode(*li);
        newNode->back = currEnd;
        newNode->next = NULL;
        currEnd->next = newNode;
    }
}
T popFront(node **li){
    if(*li == NULL)
        return;
    else{
        node *curr = *li;
        T temp = (*li)->val;
        *li = (*li)->next;
        if((*li) != NULL)
            (*li)->back = NULL;
        free(curr);
        return temp;
    }
}
T popBack(node **li){
    if(*li == NULL)
        return;
    else{
        node *curr = getEndNode(*li);
        T temp = curr->val;
        if(curr->back != NULL){
            node *newEnd = curr->back;
            newEnd->next = NULL;
            free(curr);
        }
        else
            popFront(li);
        return temp;
    }
}
void insertion(node **li, int pos, T val){
    if(*li == NULL){
        printf("\nInsertion on Empty List");
        exit(EXIT_FAILURE);
    }
    else if(pos == 0)
        pushFront(li, val);
    else{
        node *curr = getNode(*li, pos);
        node *prev = curr->back;
        node *newNode = (node *)malloc(sizeof(struct node));
        newNode->val = val;
        prev->next = newNode;
        newNode->back = prev;
        curr->back = newNode;
        newNode->next = curr;
    }
}
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
            newNode->back = curr;
            newNode->next = NULL;
            curr->next = newNode;
        }
        else{
            node *next = curr->next;
            next->back = newNode;
            newNode->next = next;
            newNode->back = curr;
            curr->next = newNode;
        }
    }
}
void deletion(node **li, int pos){
    if(*li == NULL){
        printf("\nDeletion on Empty List");
        exit(EXIT_FAILURE);
    }
    else if(pos == 0)
        popFront(li);
    else{
        node *curr = getNode(*li, pos);
        if(curr->next == NULL){
            node *prev = curr->back;
            prev->next = NULL;
            free(curr);
        }
        else{
            node *prev = curr->back;
            node *next = curr->next;
            prev->next = curr->next;
            next->back = prev;
            free(curr);
        }
    }
}

#endif // LIST_H_INCLUDED
