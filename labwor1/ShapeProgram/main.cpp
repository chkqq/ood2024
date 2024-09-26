#include <iostream>
#include "Icanvas.hpp"
#include "shape.hpp"
#include "commands.hpp"
#include "picture.hpp"

int main() 
{
    shapes::Picture picture;
    std::string command;

    std::cout << "Enter commands:\n";

    while (true)
    {
        std::getline(std::cin, command);
        if (command == "Exit")
        {
            break;
        }
        if (!commands::ExecuteCommand(command, picture))
        {
            std::cout << "Unknown command or error.\n";
        } 
    }

    return 0;
}
