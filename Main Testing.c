#include<stdio.h>

//#include"Recursive_Forward_List.h"
#include"Generic_Forward_List.h"
//#include"Generic_List.h"
//#include"Generic_Cir_List.h"


void printTest(node *list){
    printNode(list);printf("\n");
    //printNodeBack(list); //toggle this for double linked list and circular double linked list
    printf("\n");
}
int main()
{
    int testSize = 10;
    node *list = NULL;
    printf("Test insert data at the start\n");
    for(int i = 0; i < testSize; ++i)
        pushFront(&list, i);
    printTest(list);printf("\n");

    printf("\nTest getNode() is working properly?\n");
    for(int i = 0; i < testSize; ++i)
        printf("%d ", getNode(list, i)->val);
    printf("\n");

    printf("\nIs getLen() working correctly?: %d", getLen(list)==testSize);

    printf("\n\nTest delete data of the start\n");
    for(int i = 0; i < testSize; ++i)
        printf("%d ", popFront(&list));
    printf("\nResidue:\n");
    printTest(list);printf("\n");

    printf("Test insert data at the end\n");
    for(int i = 0; i < testSize; ++i)
        pushBack(&list, i);
    printTest(list);

    printf("\n\nTest delete data of the end\n");
    for(int i = 0; i < testSize; ++i)
        printf("%d ", popBack(&list));
    printf("\nResidue:\n");
    printTest(list);printf("\n");

    printf("Data Assignment\n");
    for(int i = 0; i < testSize; ++i)
        pushBack(&list, i);
    printTest(list);printf("\n");

    printf("\n\nTest insertion at the end\n");
    insertion(&list, getLen(list)-1, 100);
    printTest(list);printf("\n");

    printf("\n\nTest insertion at the start\n");
    insertion(&list, 0, 100);
    printTest(list);printf("\n");

    printf("\n\nTest deletion at the middle\n");
    deletion(&list, getLen(list)-2);
    printTest(list);printf("\n");

    printf("\n\nTest deletion at the start\n");
    deletion(&list, 0);
    printTest(list);printf("\n");

    printf("\nTest insertion after at the end\n");
    insertionAfter(&list, getLen(list)-1, 100);
    printTest(list);printf("\n");

    printf("\nTest deletion at the end\n");
    deletion(&list, getLen(list)-1);
    printTest(list);printf("\n");

    printf("\nTest insertion after at the start\n");
    insertionAfter(&list, 0, 100);
    printTest(list);printf("\n");
    printf("\nTest deletion at the middle\n");
    deletion(&list, 1);
    printTest(list);printf("\n");

    printf("\nTest insertion after at the middle\n");
    insertionAfter(&list, 2, 100);
    printTest(list);printf("\n");
    printf("\nTest deletion at the middle\n");
    deletion(&list, 3);
    printTest(list);printf("\n");

    printf("\nTest Swapping List\n");
    printf("Before\n");
    printTest(list);
    printf("\nAfter\n");
    swapNode(&list, 0, 1);
    printTest(list);
    swapNode(&list, 0, 1);
    printf("Before\n");
    printTest(list);
    printf("\nAfter\n");
    swapNode(&list, 0, 2);
    printTest(list);
    swapNode(&list, 0, 2);

    printf("swap through all\n");
    for(int i = 0; i < getLen(list); ++i){
        swapNode(&list, 0, i);
        printTest(list);
    }
    printf("swap adjacent all\n");
    for(int i = 1; i < getLen(list); ++i){
        swapNode(&list, i-1, i);
        printTest(list);
    }
    printf("swap one node between all\n");
    for(int i = 2; i < getLen(list); ++i){
        swapNode(&list, i-2, i);
        printTest(list);
    }
//    for(;;)
//        swapNode(&list, rand()%testSize, rand()%testSize);

    printf("\nTest Reverse List\n");
    printf("Before\n");
    printTest(list);
    printf("\nAfter\n");
    reverseList(&list);
    printTest(list);

    destroyList(&list);
    printTest(list);
    reverseList(&list);
    printTest(list);
    pushFront(&list, 5);
    reverseList(&list);
    printTest(list);
    pushFront(&list, 10);
    printTest(list);
    reverseList(&list);
    printTest(list);
    pushFront(&list, 17);
    printTest(list);
    reverseList(&list);
    printTest(list);
    printf("\nend of testing reverse list\n");


    printf("\nEND OF TESTING, NOW YOU MAY PROCEED TO THE ERROR TESTING\n");

    /**
     useful shortcut:
        comment         : ctrl + shift + c
        unccomment      : ctrl + shift + x
        build and run   : F9 (+fn key for some laptops)
    **/
    ///test these one-by-one. and expected result is to print error and exit from the program
    insertionAfter(&list, getLen(list)+10, 100);
    insertionAfter(&list, getLen(list), 100);
    insertion(&list, getLen(list), 100);
    insertionAfter(&list, -1, 100);
    insertion(&list,-1, 100);
    deletion(&list, getLen(list));
    deletion(&list, -1);

    return 0;
}
