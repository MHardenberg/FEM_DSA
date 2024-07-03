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
            char startChar = 'S', char endChar = 'E', char wallChar = '#');

    ~Labyrinth(); 

    char &operator()(size_t r, size_t c);

    bool &checkVisited(size_t r, size_t c);

    void show() const;
};


bool walk(Labyrinth &lab, size_t row, size_t col);

void solver(Labyrinth &lab, size_t startRow, size_t startCol);

#endif // !labyrinth_H
