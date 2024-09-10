#include <iostream>
#include "canvas.hpp"
#include "shapes.hpp"
#include "commands.hpp"

int main() {
    shapes::Picture picture;
    std::string command;

    std::cout << "Enter commands:\n";

    while (std::getline(std::cin, command)) {
        if (!commands::ExecuteCommand(command, picture)) {
            std::cout << "Unknown command or error.\n";
        }
    }

    return 0;
}
