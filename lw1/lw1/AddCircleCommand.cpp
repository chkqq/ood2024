#include "AddCircleCommand.h"

void AddCircleCommand::execute(std::vector<std::shared_ptr<Shape>>& shapes)
{
    shapes.push_back(std::make_shared<Circle>(50, sf::Vector2f(200, 200)));
}
