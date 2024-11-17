#include "CircleBuilder.h"

void CircleBuilder::buildShape(const std::string& data) {
    std::istringstream iss(data);
    std::string type;
    float radius, posX, posY;
    uint32_t fillColor, outlineColor;
    float outlineThickness;

    if (!(iss >> type >> radius >> posX >> posY >> fillColor >> outlineColor >> outlineThickness)) {
        throw std::runtime_error("Invalid data format for Circle");
    }

    if (type == "Circle") {
        circle = std::make_shared<Circle>(radius, sf::Vector2f(posX, posY));
        circle->GetCircleShape().setFillColor(sf::Color(fillColor));
        circle->GetCircleShape().setOutlineColor(sf::Color(outlineColor));
        circle->GetCircleShape().setOutlineThickness(outlineThickness);
    }
}

std::shared_ptr<Shape> CircleBuilder::getResult() {
    return circle;
}
