#include "../src/dataStructures/tree.hpp"


int main (int argc, char *argv[]) {
    BTree tree;
    tree.origin = new Node<int> {.data = 0};
    tree.origin->left = new Node<int> {.data = 1};
    tree.origin->left->left = new Node<int> {.data = 2};
    tree.origin->left->right = new Node<int> {.data = 3};


    tree.origin->right = new Node<int> {.data = -1};
    tree.origin->right->left = new Node<int> {.data = -2};
    tree.origin->right->right = new Node<int> {.data = -3};


    walkTree(&tree);

    LOGLN("Here!");
    return 0;
}
