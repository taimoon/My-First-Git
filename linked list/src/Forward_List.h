#ifndef FORWARD_LIST_H_INCLUDED
#define FORWARD_LIST_H_INCLUDED

#include <stdlib.h>
#include<stdio.h>
typedef char T;
void printFunc(T val);
void printFuncEnd();
struct node{
    T val;//you may change the T type and change the datatype of the parameters of functions below accordingly
    struct node* next;
};
typedef struct node node;
int getLen(node *li); //optional but easy
static inline  node* createNode(T val);
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
void reverseList(node **li);
void deletion(node **li, int pos);
void destroyList(node **li);
void swapNode(node **li, int pos1, int pos2);

#endif // FORWARD_LIST_H_INCLUDED
