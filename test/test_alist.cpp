#include "../src/dataStructures/arrayList.hpp"
#include <iostream>
#include <ostream>
#define LOG(desc, x) (std::cout << desc << " " << x << std::endl)
const char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main (int argc, char *argv[]) {
    ArrayList<char> list(10);

    LOG("Capacity:", list.capacity);
    LOG("Length:", list.length);

    for (size_t i = 0; i < 20; ++i) {
        list.push(chars[i]);


        LOG("Capacity:", list.capacity);
        LOG("Length:", list.length);
        LOG("*list[" << i <<"]:", *list[i]);
        LOG("", "");
    }

    for (size_t i = 0; i < 20; ++i) {
        LOG(i, *list[i]);
    }

    LOG("", "");
    return 0;
}
