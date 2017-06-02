#include "BSTree.h"

int main() {
    ElementType element[12] = {8, 10, 14, 3, 1, 6, 4, 7, 5, 19, 22, 30};
    KeyType key[5] = {13, 8, 5, 20, 6};
    int i, j, n1, n2;
    n1 = sizeof(element) / sizeof(ElementType);
    n2 = sizeof(key) / sizeof(KeyType);
    BiTree Tree, pp;
    Tree = NULL;
    CreatBST(Tree, element, n1);
    PrintTree(Tree);
    printf("\n");
    for (j = 0; j < n2; j++) {
        if (SearchBST(Tree, NULL, pp, key[j])) {
            DeleteBST(Tree, key[j]);
            PrintTree(Tree);
            printf("\n");
        }
        else {
            InsertBST(Tree, key[j]);
            PrintTree(Tree);
            printf("\n");
        }
    }
    return 0;
}
