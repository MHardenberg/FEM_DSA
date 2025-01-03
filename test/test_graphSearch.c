#include <stdio.h>
#include <stdlib.h>


typedef struct WeightedAdjMatrix {
    size_t rows, cols;
    double data[];
} WAM;


WAM* WAM_create(size_t rows, size_t cols) {
    WAM* mat = malloc(sizeof(WAM) + sizeof(double) * (rows * cols));
    mat->rows = rows;
    mat->cols = cols;
    return mat;
}


void WAM_destroy(WAM* mat) {
    free(mat);
}


double* WAM_access(WAM* mat, size_t row, size_t col) {
    if (row >= mat->rows || col >= mat->cols) {
        return NULL;
    }
        return (mat->data + (row * mat->cols + col));
}


int main() {
    fprintf(stderr, "Test\n");

    WAM* m = WAM_create(10, 10);
    double* x;
    for (size_t r = 0; r < 10; ++r) {
        for (size_t c = 0; c < 10; ++c) {
            x = WAM_access(m, r, c);
            *x = r * m->cols + c;
            fprintf(stderr, "%f ", *x); 
        }
            fprintf(stderr, "\n"); 
    }


    WAM_destroy(m);
    return 0;
}
