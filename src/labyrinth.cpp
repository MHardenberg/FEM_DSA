#include "labyrinth.hpp"
#include <cstring>


Labyrinth::Labyrinth(const char * tiles, size_t rows, size_t cols,
            char startChar, char endChar, char wallChar) {
        this->startChar = startChar;
        this->endChar = endChar;
        this->wallChar = wallChar;

        this->rows = rows;
        this->cols = cols;

        this->tiles = (char *)malloc(sizeof(char) * rows * cols + 1);
        strncpy(this->tiles, tiles, rows * cols);
        this->tiles[rows * cols] = '\0';

        this->visited = (bool *)malloc(sizeof(bool) * rows * cols);
        memset(this->visited, 0, sizeof(bool) * rows * cols);
}


Labyrinth::~Labyrinth() {
    free(this->tiles);
    free(this->visited);
}


char &Labyrinth::operator()(size_t r, size_t c) {
    size_t pos = (r * this->cols) + c;
    return this->tiles[pos];
}


bool &Labyrinth::checkVisited(size_t r, size_t c) {
    size_t pos = (r * this->cols) + c;
    return this->visited[pos];
}
