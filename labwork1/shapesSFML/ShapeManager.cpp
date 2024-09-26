#include "ShapeManager.h"
#include <SFML/Graphics.hpp>

void DrawShapes(sf::RenderWindow& window, const std::vector<ShapeDecorator*>& shapes)
{
    window.clear(sf::Color::White);
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
