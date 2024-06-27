#ifndef labyrinth_H
#define labyrinth_H

#include <cstddef>
#include <cstdlib>
#include <cstring>



struct Labyrinth {
    size_t rows, cols;
    char *tiles;
    bool *visited;

    Labyrinth(const char * tiles, size_t rows, size_t cols);

    ~Labyrinth(); 

    char &operator()(size_t r, size_t c);

    bool &markVisited(size_t r, size_t c);
};

bool walk();

void solver();

#endif // !labyrinth_H
