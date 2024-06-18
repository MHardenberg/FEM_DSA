#include "../src/bubble.h"

int main(int argc, char *argv[]) {
    if (argc > BUFF_SIZE) {
        fprintf(stderr, "Error: Input too long.\n");
        return 1;
    }
    if (argc == 1) {
        fprintf(stderr, "Error: No data.\n");
        return 1;
    }


    int array[BUFF_SIZE];
    size_t array_lenght = argc - 1;
    for (size_t i = 1; i < argc; ++i){
        array[i-1] = atoi(argv[i]);
    }

    fprintf(stderr, "Input:\n");        
    printArray(array, array_lenght);
    bubbleSort(array, array_lenght);
    fprintf(stderr, "Sorted:\n");        
    printArray(array, array_lenght);
    
    return 0;
}
