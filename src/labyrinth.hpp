#ifndef labyrinth_H
#define labyrinth_H

#include <cstddef>
#include <cstdlib>
#include <cstring>



struct Labyrinth {
    size_t rows, cols;
    char *tiles;
    bool *visited;
    char startChar, endChar, wallChar;

    Labyrinth(const char * tiles, size_t rows, size_t cols,
            char startChar = 'S', char endChar = 'E', char wallChar = 'W');

    ~Labyrinth(); 

    char &operator()(size_t r, size_t c);

    bool &checkVisited(size_t r, size_t c);
};

bool walk(Labyrinth *lab, size_t row, size_t col) {
    // if outside
    if (row >= lab->rows or col >= lab->cols) {
        return false;
    }

    // if visited
    if (lab->checkVisited(row, col)) {
        return false;
    }
    
    // if wall
    
    // if exit


};

void solver();

#endif // !labyrinth_H
