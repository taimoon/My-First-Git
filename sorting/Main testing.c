#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"Sort Algorithm.h"
typedef int T;
void printGenericArr(const void *arr, int len, size_t size,
                     void (*printFunc)(const void *val)){
    for(int i = 0; i < len; ++i)
        printFunc(arr+size*i);
}
void printFunc(void *val){
    printf("%d ", *(T *)val);
}
void arrRandAssign(T arr[], size_t len){
    for(int i = 0; i < len; ++i)
        arr[i] = rand()%UCHAR_MAX;
}

#define newline()printf("\n");
int comp(const void  *a, const void *b)
{
    return *(T *)a - *(T *)b;
}
void mainTesting(){
    //size_t len = USHRT_MAX*7.9;
    //size_t len = USHRT_MAX;
    size_t len = 13; //12 is viable number of elements for random sort works
    T arr[len];
    arrRandAssign(arr, len);
    printf("len=%d\n", sizeof(arr)/sizeof(arr[0]));
    printGenericArr(arr, len, sizeof(arr[0]), printFunc);printf("\n");
    PartitionSort(arr, len);
    //gRandomSort(arr, len, sizeof(arr[0]), comp);
    printGenericArr(arr, len, sizeof(arr[0]), printFunc);
    printf("\nsorted=%d", checkSorted(arr, len, sizeof(arr[0]), comp));
    printf("\n%d\n", gBinarySearch(&arr[4], arr, len, sizeof(arr[0]), comp));
}
int main(){
    mainTesting();
    system("PAUSE");
    return 0;
}
