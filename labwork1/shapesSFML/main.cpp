#include <SFML/Graphics.hpp>
#include "ShapeManager.h"
#include "EventManager.h"
#include "FileManager.h"
#include <iostream>
#include <memory>

int main()
{
    std::vector<std::shared_ptr<Shape>> shapes = LoadShapesFromFile("input.txt");
    SaveResultsToFile(shapes, "output.txt");

    std::vector<std::shared_ptr<Shape>> selectedShapes;

    bool isDragging = false;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes Visualization");

    while (window.isOpen())
    {
        HandleEvents(window, shapes, selectedShapes, isDragging);
        HandleMouseDrag(window, selectedShapes, isDragging);

        window.clear(sf::Color::White);

        for (const auto& shape : shapes)
        {
            shape->Draw(window);
        }

        window.display();
    }

    return 0;
}
