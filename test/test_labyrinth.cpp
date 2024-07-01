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

    lab.show();
    solver(lab, 2, 2);
    lab.show();
    return 0;
}
