#include "../src/dataStructures/llist.h"
#include <stdio.h>

int main() {
    struct LList *list_ptr = createLList();

    for (size_t x = 1; x < 100; ++x) {
        LListAppendNode(list_ptr, x);
    }
    
    LListInsertNode(list_ptr, 3, -1);
    LListDeleteNode(list_ptr, 1);

    // this should Error
    fprintf(stderr, "This should err:\t");
    LListInsertNode(list_ptr, 300, 0);

    printLList(list_ptr);
        
    freeLList(list_ptr);
    return 0;
}
