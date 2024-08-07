#include "../src/dataStructures/bTree.h"
#include <stdio.h>

int odering(BTreeNode *x, BTreeNode *y) {
    if (x->data < y->data) {
        return -1;
    }

    if (x->data > y->data) {
        return 1;
    }
    return 0;
}


int main (int argc, char *argv[]) {

    BTree* tree = create_BTree(&odering);

    int values[] = {0, 1, -1, 2, -2, 3, -3, 4, -4};

    for (size_t i = 0; i < 9; ++i) {
        BTree_addNode(tree, values[i]);
    }
    
    BTreeNode** nodes = BTree_walk(tree);
    for (size_t i = 0; i < tree->size; ++i) {
        printf("%lu: ", i);
        printf("%d, \n", nodes[i]->data);
    }

    free(nodes);
    freeBTree(tree);
    return 0;
}
