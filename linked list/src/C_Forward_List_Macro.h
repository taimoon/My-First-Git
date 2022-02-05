#ifndef C_FORWARD_LIST_MACRO_H_INCLUDED
#define C_FORWARD_LIST_MACRO_H_INCLUDED
#include <stdlib.h>
#include <stdlib.h>
#include<stdio.h>

#define ForwardListConstruct(T, printFunc)\
struct node##ForwardList##T{\
    T val;\
    struct node##ForwardList##T* next;\
};\
typedef struct node##ForwardList##T node##ForwardList##T;\
node##ForwardList##T* next##ForwardList##T(node##ForwardList##T *li){\
    return li->next;\
}\
int isEnd##ForwardList##T(node##ForwardList##T *li){\
    if(li == NULL)\
        return 1;\
    return li->next == NULL;\
}\
\
int getLen##ForwardList##T(node##ForwardList##T *li){\
    node##ForwardList##T *curr = li;\
    int len = 0;\
    while(curr != NULL){\
        curr = curr->next;\
        ++len;\
    }\
    return len;\
}\
static inline node##ForwardList##T* createNode##ForwardList##T(T val){\
    node##ForwardList##T *newNode = (node##ForwardList##T *)malloc(sizeof(struct node##ForwardList##T));\
    newNode->val = val;\
    newNode->next = NULL;\
    return newNode;\
}\
node##ForwardList##T* getNode##ForwardList##T(node##ForwardList##T *li, int pos){\
    node##ForwardList##T *curr = li;\
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
node##ForwardList##T* getEndNode##ForwardList##T(node##ForwardList##T *li){\
    if(li == NULL)\
        return NULL;\
    node##ForwardList##T *curr = li;\
    while(curr->next != NULL)\
        curr = curr->next;\
    return curr;\
};\
void pushFront##ForwardList##T(node##ForwardList##T **li, T val){\
    node##ForwardList##T *newNode = createNode##ForwardList##T(val);\
    pushFrontNode##ForwardList##T(li, &newNode);\
};\
void pushFrontNode##ForwardList##T(node##ForwardList##T **li, node##ForwardList##T **newNode){\
    (*newNode)->next = *li;\
    *li = *newNode;\
};\
void pushBack##ForwardList##T(node##ForwardList##T **li, T val){\
    node##ForwardList##T *newNode = createNode##ForwardList##T(val);\
    pushBackNode##ForwardList##T(li, &newNode);\
};\
void pushBackNode##ForwardList##T(node##ForwardList##T **li, node##ForwardList##T **newNode){\
    (*newNode)->next = NULL;\
    if(*li == NULL){\
        *li = *newNode;\
    }\
    else{\
        node##ForwardList##T *endNode = getEndNode##ForwardList##T(*li);\
        endNode->next = *newNode;\
    }\
};\
T popFront##ForwardList##T(node##ForwardList##T **li){\
    if((*li)==NULL)\
        return *(T *)NULL;\
    T val = (*li)->val;\
    node##ForwardList##T *tempNode = *li;\
    *li = (*li)->next;\
    free(tempNode);\
    return *(T *)val;\
};\
T popBack##ForwardList##T(node##ForwardList##T **li){\
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
        node##ForwardList##T *newEnd, *currEnd;\
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
void insertion##ForwardList##T(node##ForwardList##T **li, int pos, T val){\
    if(*li == NULL){\
        printf("\nInsertion on Empty List");\
        exit(0);\
    }\
    else if(pos == 0)\
        pushFront##ForwardList##T(li, val);\
    else{\
        node##ForwardList##T *prev = getNode##ForwardList##T(*li, pos-1);\
        if(prev->next == NULL){\
            printf("\nout of bound!");\
            exit(EXIT_FAILURE);\
        }\
        node##ForwardList##T *newNode = createNode##ForwardList##T(val);\
        newNode->next = prev->next;\
        prev->next = newNode;\
    }\
};\
void insertNode##ForwardList##T(node##ForwardList##T **li, int pos, node##ForwardList##T **newNode){\
    if(*li == NULL){\
        printf("\nInsertion on Empty List");\
        exit(0);\
    }\
    else if(pos == 0)\
        pushFrontNode##ForwardList##T(li, newNode);\
    else{\
        node##ForwardList##T *prev = getNode##ForwardList##T(*li, pos-1);\
        if(prev->next == NULL){\
            printf("\nout of bound!");\
            exit(EXIT_FAILURE);\
        }\
        (*newNode)->next = prev->next;\
        prev->next = (*newNode);\
    }\
};\
void insertionAfter##ForwardList##T(node##ForwardList##T **li, int pos, T val){\
    if(*li == NULL){\
        printf("\nInsertion on Empty List");\
        exit(EXIT_FAILURE);\
    }\
    else{\
        node##ForwardList##T *curr = getNode##ForwardList##T(*li, pos);\
        node##ForwardList##T *newNode = createNode##ForwardList##T(val);\
        if(curr->next == NULL){\
            newNode->next = NULL;\
        }\
        else{\
            newNode->next = curr->next;\
        }\
        curr->next = newNode;\
    }\
};\
void reverseList##ForwardList##T(node##ForwardList##T **li){\
    if(*li == NULL)\
        return;\
    node##ForwardList##T *curr, *prev1, *prev2;\
    prev2 = NULL;\
    curr = *li;\
    while(curr != NULL){\
        prev1 = curr;\
        curr = curr->next;\
        prev1->next = prev2;\
        prev2 = prev1;\
    }\
    *li=prev1;\
}\
void deletion##ForwardList##T(node##ForwardList##T **li, int pos){\
    if(*li == NULL){\
        printf("\nDeletion on Empty List");\
        exit(EXIT_FAILURE);\
    }\
    else if(pos == 0)\
        popFront##ForwardList##T(li);\
    else{\
        node##ForwardList##T *prev = getNode##ForwardList##T(*li, pos-1);\
        if(prev->next == NULL){\
            printf("\nOut of bound!");\
            exit(EXIT_FAILURE);\
        }\
        node##ForwardList##T *curr = prev->next;\
        prev->next = curr->next;\
        free(curr);\
    }\
};\
void destroyList##ForwardList##T(node##ForwardList##T **li){\
    node##ForwardList##T *prev;\
    while(*li != NULL){\
        prev = *li;\
        *li = (*li)->next;\
        free(prev);\
    }\
}\
void swapNode##ForwardList##T(node##ForwardList##T **li, int pos1, int pos2){\
    if(*li == NULL || pos1 < 0)\
        exit(EXIT_FAILURE);\
    if(pos1 == pos2)\
        return;\
    if(pos1 > pos2){\
        int temp = pos1;\
        pos1=pos2;\
        pos2=temp;\
    }\
    node##ForwardList##T *prev2 = getNode##ForwardList##T(*li, pos2-1);\
    node ##ForwardList##T*curr2 = prev2->next;\
    if(curr2 == NULL)\
        exit(EXIT_FAILURE);\
    node##ForwardList##T *next2 = curr2->next;\
    if(pos1 == 0){\
        node##ForwardList##T *curr1 = *li;\
        if(pos2 == 1){\
            curr1->next = next2;\
            curr2->next = curr1;\
        }\
        else{\
            node##ForwardList##T *next1 = curr1->next;\
            curr1->next = next2;\
            prev2->next = curr1;\
            curr2->next = next1;\
        }\
        *li = curr2;\
    }\
    else{\
        node##ForwardList##T *prev1 = getNode##ForwardList##T(*li, pos1-1);\
        node##ForwardList##T *curr1 = prev1->next;\
        if(curr1 == prev2){\
            curr1->next = next2;\
            curr2->next = curr1;\
            prev1->next = curr2;\
        }\
        else{\
            node##ForwardList##T *next1 = curr1->next;\
            prev1->next = curr2;\
            curr1->next = next2;\
            prev2->next = curr1;\
            curr2->next = next1;\
        }\
    }\
}\
void printSeq##ForwardList##T(node##ForwardList##T *li){\
    while(li != NULL){\
        printFunc(li->val);\
        li = li->next;\
    }\
}

#define node(T, C) node##C##T
#define printSeq(T, C, base) printSeq##C##T(base)
#define getLen(T, C, base) getLen##C##T(base)
#define getNode(T, C, base, pos) getNode##C##T(base, pos)
#define getEndNode(T, C, base) getEndNode##C##T(base)
#define pushFront(T, C, base, val) pushFront##C##T(&base, val)
#define pushBack(T, C, base, val) pushBack##C##T(&base, val)
#define popFront(T, C, base) popFront##C##T(&base)
#define popBack(T, C, base) popFront##C##T(&base)
#define insertion(T, C, base, pos, val) insertion##C##T(&base, pos, val)
#define insertionAfter(T, C, base, pos, val) insertionAfter##C##T(&base, pos, val)
#define reverseList(T, C, base) reverseList##C##T(&base)
#define deletion(T, C, base, pos) deletion##C##T(&base, pos)
#define destroyList(T, C, base) destroyList##C##T(&base)
#define swapNode(T, C, base, pos1, pos2) swapNode##C##T(&base, pos1, pos2)
#define next(T, C, curr) next##C##T(curr)
#define isEnd(T, C, curr) isEnd##C##T(curr)
#endif // C_FORWARD_LIST_MACRO_H_INCLUDED
