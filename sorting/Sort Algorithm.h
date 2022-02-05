#ifndef SORT_ALGORITHM_H_INCLUDED
#define SORT_ALGORITHM_H_INCLUDED
#include<stdlib.h>
/**
    note that the generic using void *(memcpy) and void **
    void ** approach sometimes failed

    partition sort is an alias for quick sort
    random sort is intended to be inefficient and a joke
**/
int checkSorted(void *arr, size_t len, size_t elemSize, int (*cmp)(const void *a, const void *b)){
    for(int i = 1; i < len; ++i){
        if(cmp(arr+elemSize*i, arr+elemSize*(i-1)) < 0){
            return 0;
        }
    }
    return 1;
}
int gBinarySearch(const void* key, const void *arr,
                  size_t len, size_t elemSize,
                  int(*comparator)(const void*, const void*))
{
    int low = 0;
    int high = len-1;
    int mid = (high+low)/2;
    do
    {
        if(comparator(arr+mid*elemSize, key) < 0)
            low = mid+1;
        else if(comparator(arr+mid*elemSize, key) > 0)
            high = mid-1;
        else
            return mid;
        mid = (high+low)/2;
    }while(low <= high);
    return -1;
}
void swapping(void **a, void **b){
    void *temp = *a;
    *a = *b;
    *b = temp;
}
void gSwap(void *a, void *b, size_t size){
    void *temp = malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}
void assign(void *a, void *b, size_t elemSize){
    memcpy(a, b, elemSize);
}
void BubbleSort(int arr[], size_t len){
    char swapped = 1;
    while(swapped){
        swapped = 0;
        for(size_t i = 1; i < len; ++i){
            if(arr[i-1]>arr[i]){
                swapping(&arr[i-1],&arr[i]);
                swapped = 1;
            }
        }
    }
}
void gBubbleSort(void *arr, size_t len, size_t elemSize,
                 int(*cmp)(const void*, const void*)){
    char swapped = 1;
    while(swapped){
        swapped = 0;
        for(size_t i = 1; i < len; ++i){
            if((cmp(arr+elemSize*(i-1),arr+elemSize*i)) > 0){
                gSwap(arr+elemSize*(i-1),arr+elemSize*i, elemSize);
                swapped = 1;
            }
        }
    }
}
void SelectionSort(int arr[], size_t len){
    int smallest;
    for(size_t i = 0; i < len; ++i){
        smallest = i;
        for(size_t j = i+1; j < len; ++j){
            if(arr[j]<arr[smallest])
                smallest = j;
        }
        swapping(&arr[i],&arr[smallest]);
    }
}
void gSelectionSort(void *arr, size_t len, size_t elemSize,
                 int(*cmp)(const void*, const void*)){
    int smallest;
    for(size_t i = 0; i < len; ++i){
        smallest = i;
        for(size_t j = i+1; j < len; ++j){
            if(cmp(arr+j*elemSize,arr+smallest*elemSize)<0)
                smallest = j;
        }
        gSwap(arr+i*elemSize,arr+smallest*elemSize, elemSize);
    }
}
void InsertionSort(int arr[], size_t len){
    for(size_t i = 1; i < len; ++i){
        int j = i;
        while(j > 0 && arr[j-1]>arr[j])
             arr[j]=arr[j--];
        arr[j] = arr[i];
    }
}
void gInsertionSort(void *arr, size_t len, size_t elemSize,
                 int(*cmp)(const void*, const void*)){
    for(size_t i = 1; i < len; ++i){
        int j = i;
        while(j > 0 && cmp(arr+(j-1)*elemSize, arr+j*elemSize) > 0){
            assign(arr+j*elemSize, arr+(j-1)*elemSize, elemSize);
            --j;
        }
         assign(arr+j*elemSize, arr+i*elemSize, elemSize);
    }
}
//arr[p..q] and arr[q+1..len]
void Merge(int arr[], int p, int q, size_t len){
    int n1 = q-p+1;
    int n2 = len-q;
    int *leftArr = (int *)malloc((n1)*sizeof(int));
    int *rightArr = (int *)malloc((n2)*sizeof(int));
    for(int i = 0; i < n1; ++i)
        leftArr[i] = arr[p+i];
    for(int i = 0; i < n2; ++i)
        rightArr[i] = arr[q+1+i];
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    while(i < n1 && j < n2){
        if(leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }
    while(i < n1)
        arr[k++] = leftArr[i++];
    while(j < n2)
        arr[k++] = rightArr[j++];
    free(leftArr);
    free(rightArr);
}

void MergeSortReccur(int arr[], int left, size_t len){
    if(left < len){
        int m = (left+len-1)/2;
        MergeSortReccur(arr, left, m);
        MergeSortReccur(arr, m+1, len);
        Merge(arr, left, m, len);
    }
}
void MergeSort(int arr[], size_t len){
    MergeSortReccur(arr, 0, len);
}
//arr[p..q] and arr[q+1..len]
void gMerge(void *arr, int p, int q,
            size_t len, size_t elemSize,
            int(*cmp)(const void*, const void*)){
    int n1 = q-p+1;
    int n2 = len-q;
    void *leftArr = malloc(n1*elemSize);
    void *rightArr = malloc(n2*elemSize);
    for(int i = 0; i < n1; ++i)
        assign(leftArr+i*elemSize, arr+(p+i)*elemSize, elemSize);
    for(int i = 0; i < n2; ++i)
        assign(rightArr+i*elemSize, arr+(q+1+i)*elemSize, elemSize);
    int i, j, k;
    i=j=0;
    k=p;
    while(i < n1 && j < n2){
        if(cmp(leftArr+i*elemSize, rightArr+j*elemSize) <= 0)
            assign(arr+(k++)*elemSize, leftArr+(i++)*elemSize, elemSize);
            //arr[k++] = rightArr[i++];
        else
            assign(arr+(k++)*elemSize, rightArr+(j++)*elemSize, elemSize);
            //arr[k++] = rightArr[j++];
    }
    while(i < n1)
        assign(arr+(k++)*elemSize, leftArr+(i++)*elemSize, elemSize);
        //arr[k++] = leftArr[i++];
    while(j < n2)
        assign(arr+(k++)*elemSize, rightArr+(j++)*elemSize, elemSize);
        //arr[k++] = rightArr[j++];
    free(leftArr);
    free(rightArr);
}
void gMergeSortReccur(void *arr, int left,
                        size_t len, size_t elemSize,
                        int(*cmp)(const void*, const void*)){
    if(left < len){
        int m = (left+len-1)/2;
        gMergeSortReccur(arr, left, m, elemSize, cmp);
        gMergeSortReccur(arr, m+1, len, elemSize, cmp);
        gMerge(arr, left, m, len, elemSize, cmp);
    }
}
void gMergeSort(void *arr, size_t len, size_t elemSize,
                 int(*cmp)(const void*, const void*)){
    gMergeSortReccur(arr, 0, len, elemSize, cmp);
}
//l=left, r=right, arr[l..r]
int Partition(int arr[], int l, int r){
    int i = l-1;
    int p = r;
    int pivot = arr[p];
    for(int j = l; j < r; ++j)
        if(arr[j] <= pivot)
            swapping(&arr[++i], &arr[j]);
    swapping(&arr[i+1], &arr[p]);
    return i+1;
}
void PartitionSortRecur(int arr[], int l, int r){
    if(l < r){
        int p = Partition(arr, l, r);
        PartitionSortRecur(arr, l, p-1);
        PartitionSortRecur(arr, p+1, r);
    }
}
void PartitionSort(int arr[], int len){
    PartitionSortRecur(arr, 0, len-1);
}
//arr[l..r]
int gPartition(void* arr, int l, int r, size_t elemSize, int (*cmp)(const void*, const void*)){
    int i = l-1;
    void *pivot = arr+r*elemSize;//int pivot = arr[r];
    for(int j = l; j < r; ++j)
        if(cmp(arr+j*elemSize, pivot) <= 0)//if(arr[j] <= pivot)
            gSwap(arr+elemSize*++i, arr+j*elemSize, elemSize);//swapping(&arr[++i], &arr[j]);
    gSwap(arr+elemSize*++i, arr+r*elemSize, elemSize);//swapping(&arr[i+1], &arr[r]);
    return i;
}
void gPartitionSortRecur(void* arr, int l, int r, size_t elemSize, int (*cmp)(const void*, const void*)){
    if(l < r){
        int p = gPartition(arr, l, r, elemSize, cmp);
        gPartitionSortRecur(arr, l, p-1, elemSize, cmp);
        gPartitionSortRecur(arr, p+1, r, elemSize, cmp);
    }
}
void gPartitionSort(void* arr, size_t len, size_t elemSize, int (*cmp)(const void*, const void*)){
    gPartitionSortRecur(arr, 0, len-1, elemSize, cmp);
}
void gRandomSort(void* arr, size_t len, size_t elemSize, int (*cmp)(const void*, const void*)){
    while(checkSorted(arr, len, elemSize, cmp) == 0){
        int a = rand()%len;
        int b = rand()%len;
        while(a == b)
            a = rand()%len;
        gSwap(arr+elemSize*a, arr+elemSize*b, elemSize);
    }
}
#endif // SORT_ALGORITHM_H_INCLUDED
