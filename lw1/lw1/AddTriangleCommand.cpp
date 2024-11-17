#include "AddTriangleCommand.h"

void AddTriangleCommand::execute(std::vector<std::shared_ptr<Shape>>& shapes)
{
    shapes.push_back(std::make_shared<Triangle>(sf::Vector2f(100, 200), sf::Vector2f(200, 200), sf::Vector2f(150, 100)));
}
