#include <cstddef>
#include <iostream>
#include "../src/labyrinth.hpp"
#define LOG(x) (std::cout << x)
#define LOGLN(x) (std::cout << x << std::endl)


int main (int argc, char *argv[]) {

    Labyrinth lab(
        "#####E##"
        "#      #"
        "##S#####",
            3, 8);

    for (size_t r = 0; r < lab.rows; ++r) {
        for (size_t c = 0; c < lab.cols; ++c) {
            LOG(lab(r,c));
        }
        LOGLN("");
    }




    return 0;
}
