#include <iostream>
#include "../src/labyrinth.hpp"
#define LOG(x) (std::cout << x)
#define LOGLN(x) (std::cout << x << std::endl)


int main (int argc, char *argv[]) {

    Labyrinth lab(
        "#####E##########"
        "# # #      #  ##"
        "#   ##### ## ###"
        "# # #  #       #"
        "# #        #####"
        "# ##########   #"
        "#  #         # #"
        "## # ######### #"
        "#     #     ## #"
        "####### #   #  #"
        "# #  ## # # # ##"
        "#       #      #"
        "##S#############",
            13, 16);

    lab.show();
    solver(lab, 12, 2);
    lab.show();
    return 0;
}
