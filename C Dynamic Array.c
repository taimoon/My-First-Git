#include<stdio.h>
#include<stdlib.h>
typedef char ArrT;
void printFunc(ArrT data){
    printf("%d ", data);
}
//print character after each is printed in printArr
void printFuncEnd(){printf(" ");};
///implement dynamic array like the vector of STL C++. It grows and shrinks automatically.
struct array{
    ArrT *arrPtr;
    int front;
    int currSize;
    int maxSize;
};
typedef struct array array;
array array_init = {NULL, 0, 0, 0};

void printArr(array arr){
    if(arr.currSize > 0){
        for(int i = arr.front; i < arr.currSize; ++i){
            printFunc(arr.arrPtr[i]);
            printFuncEnd();
        }
    }
}
int getLen(array arr){
    if(arr.arrPtr != NULL)
        return arr.currSize-arr.front+1;
    return 0;
}
ArrT* getElem(array arr, int pos){
    if(pos < 0 || pos >= getLen(arr)-1)
        exit(EXIT_FAILURE);
    else
        return &(arr.arrPtr[arr.front+pos]);
}
ArrT* initialiseArray(int len, size_t dataSize){
    return malloc(len*dataSize);
}
void constructDynamicArray(array *arr){
    if(arr->arrPtr == NULL){
        if(arr->arrPtr != NULL)
            free(arr->arrPtr);
        arr->arrPtr = initialiseArray(2, sizeof(ArrT));
        arr->front = 0;
        arr->currSize = 0;
        arr->maxSize = 2;
    }
}
void shrinkArray(array *arr){
    if(arr->arrPtr == NULL)
        return;
    int currLen = getLen(*arr);
    if(currLen != 0 && currLen*2 < arr->maxSize){
        if(arr->maxSize/2 > 0){
            for(int i = arr->front; i < arr->currSize; ++i)
                arr->arrPtr[i-arr->front]=arr->arrPtr[i];
            arr->currSize = currLen-1;
            arr->front = 0;
            arr->maxSize /= 2;
            arr->arrPtr = (ArrT *)realloc(arr->arrPtr, sizeof(ArrT)*arr->maxSize);
        }
    }else if(currLen == 0 && arr->arrPtr != NULL){
            free(arr->arrPtr);
            *arr = array_init;
    }
}
void growArray(array *arr){
    int currLen = getLen(*arr);
    if(arr->maxSize == 0)
        constructDynamicArray(arr);
    else if (currLen+1 >= arr->maxSize){
        for(int i = arr->front; i < arr->currSize; ++i)
                arr->arrPtr[i-arr->front]=arr->arrPtr[i];
        arr->currSize = currLen-1;
        arr->front = 0;
        arr->maxSize *= 2;
        arr->arrPtr = (ArrT *)realloc(arr->arrPtr, sizeof(ArrT)*arr->maxSize);
    }
}


///end of dynamic array
/**
    we use the same array data structure for stack and queue
    The difference is on removing.
    removing a stack is removing the most recent added
    removing a queue is removing the least recent added.
**/
void push(ArrT data, array *stack){
    shrinkArray(stack);
    growArray(stack);
    stack->arrPtr[stack->currSize] = data;
    stack->currSize += 1;
}
ArrT pop(array *stack){
    if(stack->currSize == 0)
        return NULL;
    stack->currSize -= 1;
    ArrT top = stack->arrPtr[stack->currSize];
    shrinkArray(stack);
    return top;
}
void enqueue(ArrT data, array *q){
    push(data, q);
}
ArrT dequeue(array *q){
    ArrT front = q->arrPtr[q->front];
    q->front += 1;
    shrinkArray(q);
    return front;
}
int main(){
    int testLen = 16;
    array arr = array_init;
    for(int i = 0; i < testLen; ++i)
        push(i, &arr);
    printArr(arr);printf("\n");
    ArrT *tempPtr = getElem(arr, 5);
    *tempPtr = 50;
    printFunc(*(getElem(arr, 5)));printf("\n");
    printArr(arr);printf("\n");
    for(int i = 0; i < testLen; ++i)
        printFunc(dequeue(&arr));

    for(;;){
        for(int i = 0; i < testLen; ++i)
            push(i, &arr);
        for(int i = 0; i < testLen; ++i)
            pop(&arr);
        for(int i = 0; i < testLen; ++i)
            push(i, &arr);
        for(int i = 0; i < testLen; ++i)
            dequeue(&arr);

    }
}
