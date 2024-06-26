#include <iostream>
#include <ostream>
#include <stdio.h>
#include "../src/dataStructures/stack.hpp"


int main (int argc, char *argv[]) {
    const char data[] = "abcdefghijklmno";
    Stack<char> stack;

    std::cout << "Data: " << data << std::endl;

    std::cout << "Pushing:" << std::endl;
    for (size_t i = 0; i < 15; ++i) {
        char l = data[i];
        stack.push(l);
        std::cout << '\t' << *stack.peek() << " lenght: " << stack.length << std::endl;
    }

    std::cout << "Popping:" << std::endl;
    while (stack.length) {
        std::cout << '\t' << stack.pop() << " lenght after pop: "
            << stack.length << std::endl;
    }

    return 0;
}
