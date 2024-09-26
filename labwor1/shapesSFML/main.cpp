#include <SFML/Graphics.hpp>
#include "InputParser.h"

std::vector<ShapeDecorator*> LoadShapes(const std::string& filename)
{
    return LoadShapesFromFile(filename);
}

void SaveShapesToFile(const std::vector<ShapeDecorator*>& shapes, const std::string& filename)
{
    SaveResultsToFile(shapes, filename);
}

void HandleEvents(sf::RenderWindow& window) 
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

void DrawShapes(sf::RenderWindow& window, const std::vector<ShapeDecorator*>& shapes)
{
    window.clear();
    for (auto& shape : shapes)
    {
        shape->Draw(window);
    }
    window.display();
}

void CleanUpShapes(std::vector<ShapeDecorator*>& shapes)
{
    for (auto& shape : shapes) 
    {
        delete shape;
    }
    shapes.clear();
}

int main()
{
    std::vector<ShapeDecorator*> shapes = LoadShapes("input.txt");

    sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes Visualization");
    SaveShapesToFile(shapes, "output.txt");

    while (window.isOpen()) 
    {
        HandleEvents(window);
        DrawShapes(window, shapes);
    }

    CleanUpShapes(shapes);

    return 0;
}
