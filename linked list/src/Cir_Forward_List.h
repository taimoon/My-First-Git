#ifndef CIR_FORWARD_LIST_H_INCLUDED
#define CIR_FORWARD_LIST_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
struct node{
    char val;//you may change the char type and change the parameter of functions below accordingly
    struct node* next;
};
typedef struct node node;
typedef struct node* nodePtr;
int getLen(node *li); //optional but easy
node* getNode(node *li, int pos);
node* getEndNode(node *li);
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
        }while(i < pos && !(curr == li));
        if(curr == li){
                printf("\nout of bound!");
                exit(EXIT_FAILURE);
        }
        return curr;
    }
}
node* getEndNode(node *li){
    node *curr = li;
    while(curr->next != li)
        curr = curr->next;
    return curr;
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

void pushFront(node **li, char val){
    node *newNode = (node *)malloc(sizeof(struct node));
    newNode->val = val;
    if(*li == NULL){
        newNode->next = newNode;
        *li = newNode;
    }
    else{
        node *endNode = getEndNode(*li);
        endNode->next = newNode;
        newNode->next = *li;
        *li = newNode;
    }
};
void pushBack(node **li, char val){
    if(*li == NULL)
        pushFront(li, val);
    else{
        node *newNode = (node *)malloc(sizeof(struct node));
        node *endNode = getEndNode(*li);
        newNode->val = val;
        newNode->next = *li;
        endNode->next = newNode;
    }
};
char popFront(node **li){
    char val;
    if((*li)==NULL)
        return NULL;
    else if((*li)->next == *li){
        val = (*li)->val;
        free(*li);
        *li = NULL;
        return val;
    }
    else{
        val = (*li)->val;
        node *endNode = getEndNode(*li);
        node *tempNode = *li;
        endNode->next = tempNode->next;
        *li = (*li)->next;
        free(tempNode);
        return val;
    }
};
char popBack(node **li){
    char val;
    if(*li == NULL)
        return NULL;
    else if((*li)->next == *li){
        val = (*li)->val;
        free(*li);
        *li = NULL;
        return val;
    }
    else{
        node *newEnd, *currEnd;
        newEnd = *li;
        while(newEnd->next->next != *li)
            newEnd = newEnd->next;
        currEnd = newEnd->next;
        val = currEnd->val;
        newEnd->next = *li;
        free(currEnd);
        return val;
    }
};
void insertion(node **li, int pos, char val){
    if(*li == NULL){
        printf("\nInsertion on Empty List");
        exit(0);
    }
    else if(pos == 0)
        pushFront(li, val);
    else{
        node *prev = getNode(*li, pos-1);
        if(prev->next == *li){
            printf("\nout of bound!");
            exit(EXIT_FAILURE);
        }
        node *newNode = (node *)malloc(sizeof(struct node));
        newNode->val = val;
        newNode->next = prev->next;
        prev->next = newNode;
    }
};
void insertionAfter(node **li, int pos, char val){
    if(*li == NULL){
        printf("\nInsertion on Empty List");
        exit(EXIT_FAILURE);
    }
    else{
        node *curr = getNode(*li, pos);
        node *newNode = (node *)malloc(sizeof(struct node));
        newNode->val = val;
        newNode->next = curr->next;
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
        if(prev->next == *li){
            printf("\nOut of bound!");
            exit(EXIT_FAILURE);
        }
        node *curr = prev->next;
        prev->next = curr->next;
        free(curr);
    }
};


#endif // CIR_FORWARD_LIST_H_INCLUDED
