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

static inline void walk (BTree *tree, enum Order order) {
    BTreeNode** nodes = BTree_walk(tree, order);
    for (size_t i = 0; i < tree->size; ++i) {
        printf("%lu: ", i);
        printf("%d, \n", nodes[i]->data);
    }

    free(nodes);
}


int main (int argc, char *argv[]) {

    BTree* tree = create_BTree(&odering);

    int values[] = {0, -3, -2, -4, 3, 2, 4}; 

    for (size_t i = 0; i < 7; ++i) {
        BTree_addNode(tree, values[i]);
    }
    
    printf("Base order:\n");
    walk(tree, base);

    printf("Pre order:\n");
    walk(tree, preOrder);

    printf("Post order:\n");
    walk(tree, postOrder);
    

    freeBTree(tree);
    return 0;
}
