#ifndef CIR_LIST_H_INCLUDED
#define CIR_LIST_H_INCLUDED

#include <stdlib.h>
#include<stdio.h>
struct node{
    char val;//you may change the char type and change the parameter of functions below accordingly
    struct node* next;
    struct node* back;
};
typedef struct node node;
typedef struct node* nodePtr;
int getLen(node *li); //optional but easy
node* getNode(node *li, int pos);
node* getEndNode(node *li);///trivial for circular double linked list
void printNode(node *li);
void pushFront(node **li, char val);
void pushBack(node **li, char val);
char popFront(node **li);//you may change the char to void so that it doesn't return anything
char popBack(node **li);//you may change the char to void so that it doesn't return anything
void insertion(node **li, int pos, char val);
void insertionAfter(node **li, int pos, char val); //optional
void deletion(node **li, int pos);


int getLen(node *li){
    node *curr = li;
    int len = 0;
    if(curr != NULL){
        do{
            curr = curr->next;
            ++len;
        }while(curr != li);
    }
    return len;
}
node* getNode(node *li, int pos){
    node *curr = li;
    if(pos < 0){
            printf("\nNo Negative Bound");
            exit(EXIT_FAILURE);
    }
    else if(pos == 0)
        return li;
    else{
        int i = 0;
        do{
            curr = curr->next;
            ++i;
        }while(i < pos && curr != li);
        if(curr == li){
                printf("\nout of bound!");
                exit(EXIT_FAILURE);
        }
        return curr;
    }
}
node* getEndNode(node *li){
    if(li == NULL)
        return NULL;
    return li->back;
};
void printNode(node *li){
    node *curr = li;
    if(li == NULL)
        return;
    do{
        printf("%d ", curr->val);
        curr = curr->next;
    }while(curr != li);
}
void printNodeBack(node *li){
    if(li == NULL)
        return;
    node *curr  = li->back;
    do{
        printf("%d ", curr->val);
        curr = curr->back;
    }while(curr != li->back);

}
void pushFront(node **li, char val){
    node *newNode = (node *)malloc(sizeof(struct node));
    newNode->val = val;
    if(*li == NULL){
        newNode->next = newNode;
        newNode->back = newNode;
    }
    else if((*li)->next == *li){
        (*li)->next = newNode;
        (*li)->back = newNode;
        newNode->next = *li;
        newNode->back = *li;
    }
    else{
        node *endNode = getEndNode(*li);
        newNode->next = *li;
        (*li)->back = newNode;
        newNode->back = endNode;
        endNode->next = newNode;
    }
    *li = newNode;
}
void pushBack(node **li, char val){
    if(*li == NULL)
        pushFront(li, val);
    else if((*li)->next == *li){
        node *newNode = (node *)malloc(sizeof(struct node));
        newNode->val = val;
        (*li)->next = newNode;
        (*li)->back = newNode;
        newNode->next = *li;
        newNode->back = *li;
    }
    else{
        node *newNode = (node *)malloc(sizeof(struct node));
        newNode->val = val;
        node *currEnd = getEndNode(*li);
        newNode->back = currEnd;
        newNode->next = *li;
        currEnd->next = newNode;
        (*li)->back = newNode;
    }
}
char popFront(node **li){
    char val;
    if(*li == NULL)
        return;
    else if((*li)->next == *li){
        val = (*li)->val;
        free(*li);
        *li = NULL;
        return val;
    }
    else{
        node *curr = *li;
        node *endNode = getEndNode(*li);
        char temp = (*li)->val;
        *li = (*li)->next;
        (*li)->back = endNode;
        endNode->next = *li;
        free(curr);
        return temp;
    }
}
char popBack(node **li){
    char val;
    if(*li == NULL)
        return;
    else if((*li)->next == *li){
        val = (*li)->val;
        free(*li);
        *li = NULL;
        return val;
    }
    else{
        node *curr = getEndNode(*li);
        node *prev = curr->back;
        char temp = curr->val;
        prev->next = *li;
        (*li)->back = prev;
        free(curr);
        return temp;
    }
}
void insertion(node **li, int pos, char val){
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
void insertionAfter(node **li, int pos, char val){
    if(*li == NULL){
        printf("\nInsertion on Empty List");
        exit(EXIT_FAILURE);
    }
    else{
        node *curr = getNode(*li, pos);
        node *newNode = (node *)malloc(sizeof(struct node));
        newNode->val = val;
        node *next = curr->next;
        next->back = newNode;
        newNode->next = next;
        newNode->back = curr;
        curr->next = newNode;
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
        node *prev = curr->back;
        prev->next = curr->next;
        curr->next->back = prev;
        free(curr);
    }
}
#endif // CIR_LIST_H_INCLUDED
