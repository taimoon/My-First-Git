#include"tree.h"
#include<stdio.h>
#include<stdlib.h>

int main(){
    nodePtr tree = NULL;
    int len = 10;
    for(int i = 0; i < len; ++i)
        insertion(&tree, rand()%len);
    printBinaryTree(tree, 0, len);
    printInorder(tree);printf("\n");
    printPostorder(tree);printf("\n");
    printPreorder(tree);printf("\n");
    printf("\nmax=");printFunc((maxNode(tree))->data);printf("\n");
    printf("\nmin=");printFunc((minNode(tree))->data);printf("\n");
    printf("\nDelete ");printFunc(maxNode(tree)->data);
    deletion(&tree, (maxNode(tree))->data);
    printBinaryTree(tree, 0, len);printf("\nend\n");
    printf("\nDelete ");printFunc(minNode(tree)->data);
    deletion(&tree, (minNode(tree))->data);
    printBinaryTree(tree, 0, len);printf("\nend\n");
    printf("\nDelete 7\n");
    deletion(&tree, 7);
    printBinaryTree(tree, 0, len);printf("\nend\n");
    printf("\nDelete 5\n");
    deletion(&tree, 5);
    printBinaryTree(tree, 0, len);printf("\nend\n");
    for(;;){
        insertion(&tree, 5);
        deletion(&tree, 5);
    }
    return 0;
}
