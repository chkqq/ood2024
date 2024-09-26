#include <SFML/Graphics.hpp>
#include "ShapeManager.h"
#include "EventManager.h"
#include "FileManager.h"
#include <iostream>

int main()
{
    std::vector<ShapeDecorator*> shapes = LoadShapesFromFile("input.txt");
    sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes Visualization");
    SaveResultsToFile(shapes, "output.txt");

    while (window.isOpen())
    {
        HandleEvents(window);
        DrawShapes(window, shapes);
    }

    CleanUpShapes(shapes);

    return 0;
}
