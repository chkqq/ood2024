#include <SFML/Graphics.hpp>
#include "ShapeManager.h"
#include "EventManager.h"
#include "FileManager.h"
#include <iostream>
#include <memory>
#include <vector>

int main()
{
    std::vector<std::shared_ptr<Shape>> shapes = LoadShapesFromFile("input.txt");
    SaveResultsToFile(shapes, "output.txt");

    std::vector<std::shared_ptr<Shape>> selectedShapes;
    std::vector<std::shared_ptr<ShapeGroup>> groups;

    bool isDragging = false;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes Visualization");

    while (window.isOpen())
    {
        HandleEvents(window, shapes, selectedShapes, isDragging, groups);
        HandleMouseDrag(window, selectedShapes, isDragging, groups);

        window.clear(sf::Color::White);
        for (const auto& shape : shapes)
        {
            shape->Draw(window);
        }
        for (const auto& selectedShape : selectedShapes)
        {
            selectedShape->Draw(window);
        }
        for (const auto& group : groups)
        {
            group->Draw(window);
        }
        window.display();
    }

    return 0;
}
