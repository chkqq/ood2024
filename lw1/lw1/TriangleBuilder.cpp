#include "TriangleBuilder.h"

void TriangleBuilder::buildShape(const std::string& data) {
    std::istringstream iss(data);
    std::string type;
    float x1, y1, x2, y2, x3, y3;
    uint32_t fillColor, outlineColor;
    float outlineThickness;

    if (!(iss >> type >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> fillColor >> outlineColor >> outlineThickness)) {
        throw std::runtime_error("Invalid data format for Triangle");
    }

    if (type == "Triangle") {
        triangle = std::make_shared<Triangle>(sf::Vector2f(x1, y1), sf::Vector2f(x2, y2), sf::Vector2f(x3, y3));
        triangle->GetTriangleShape().setFillColor(sf::Color(fillColor));
        triangle->GetTriangleShape().setOutlineColor(sf::Color(outlineColor));
        triangle->GetTriangleShape().setOutlineThickness(outlineThickness);
    }
}

std::shared_ptr<Shape> TriangleBuilder::getResult() {
    return triangle;
}
