#include "RectangleBuilder.h"

void RectangleBuilder::buildShape(const std::string& data) {
    std::istringstream iss(data);
    std::string type;
    float width, height, posX, posY;
    uint32_t fillColor, outlineColor;
    float outlineThickness;

    if (!(iss >> type >> width >> height >> posX >> posY >> fillColor >> outlineColor >> outlineThickness)) {
        throw std::runtime_error("Invalid data format for Rectangle");
    }

    if (type == "Rectangle") {
        rectangle = std::make_shared<Rectangle>(sf::Vector2f(width, height), sf::Vector2f(posX, posY));
        rectangle->GetRectangleShape().setFillColor(sf::Color(fillColor));
        rectangle->GetRectangleShape().setOutlineColor(sf::Color(outlineColor));
        rectangle->GetRectangleShape().setOutlineThickness(outlineThickness);
    }
}

std::shared_ptr<Shape> RectangleBuilder::getResult() {
    return rectangle;
}
