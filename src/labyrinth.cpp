#include "labyrinth.hpp"
#include <cstring>


Labyrinth::Labyrinth(const char * tiles, size_t rows, size_t cols) {
        this->rows = rows;
        this->cols = cols;

        this->tiles = (char *)malloc(sizeof(char) * rows * cols + 1);
        strncpy(this->tiles, tiles, rows * cols);

        this->visited = (bool *)malloc(sizeof(char) * rows * cols);
        memset(this->visited, 0, sizeof(bool) * rows * cols);
        this->tiles[rows * cols] = '\0';
    }

Labyrinth::~Labyrinth() {
    free(this->tiles);
    free(this->visited);
}

char &Labyrinth::operator()(size_t r, size_t c) {
    size_t pos = (r * this->cols) + c;
    return this->tiles[pos];
}

bool &Labyrinth::markVisited(size_t r, size_t c) {
    size_t pos = (r * this->cols) + c;
    return this->visited[pos];
}
