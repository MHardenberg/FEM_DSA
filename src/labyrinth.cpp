#include "labyrinth.hpp"
#include <cstring>
#include <iostream>

#define LOG(x) (std::cout << x)
#define LOGLN(x) (std::cout << x << std::endl)

struct Direction {
    int x, y;
};

const Direction dirs[] = {
    {.x = 1, .y = 0,},
    {.x = 0, .y = 1,},
    {.x = -1, .y = 0,},
    {.x = 0, .y = -1,},
};

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


void Labyrinth::show() const {
    for (size_t r = 0; r < this->rows; ++r) {
        for (size_t c = 0; c < this->cols; ++c) {
            size_t pos = (r * this->cols) + c;
            LOG(this->tiles[pos]);
        }
        std::cout << '\n';
    }
}


char &Labyrinth::operator()(size_t r, size_t c) {
    size_t pos = (r * this->cols) + c;
    return this->tiles[pos];
}


bool &Labyrinth::checkVisited(size_t r, size_t c) {
    size_t pos = (r * this->cols) + c;
    return this->visited[pos];
}

bool walk(Labyrinth &lab, size_t row, size_t col) {
    LOG("Considering: " << row << " " << col);
    // if outside
    if (row >= lab.rows or col >= lab.cols) {
        LOGLN("  outside");
        return false;

    }

    // if visited
    if (lab.checkVisited(row, col)) {
        LOGLN("  visited");
        return false;
    } else {   
        lab.checkVisited(row, col) = true;
    }

    char t = lab(row, col);
    // if wall
    if (t == lab.wallChar) {
        LOGLN("  wall");
        return false;
    }
    
    // if exit
    if (t == lab.endChar) {
        LOGLN("  exit");
        lab(row, col) = '*';
        return true;
    }
    
    LOGLN("");
    for (size_t i = 0; i < 4; ++i) {
        int newRow = (int)row + dirs[i].x;
        int newCol = (int)col + dirs[i].y;
        if (newRow < 0 || newCol < 0) {continue;}

        if (walk(lab, newRow, newCol)) {
            LOGLN("  backtracking");
            lab(row, col) = '*';
            return true;
        }
    }

    LOGLN("Dead path....");
    return false;
}


void solver(Labyrinth &lab, size_t startRow, size_t startCol) {
    walk(lab, startRow, startCol);

}
