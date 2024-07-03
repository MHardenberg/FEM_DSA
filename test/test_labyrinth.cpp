#include "../src/labyrinth.hpp"


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
