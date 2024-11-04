#include "ShapeBuilder.h"
#include "Circle.h"
#include <sstream>

class CircleBuilder : public ShapeBuilder {
private:
    std::shared_ptr<Circle> circle;

public:
    void buildShape(const std::string& data) override {
        std::istringstream iss(data);
        std::string type;
        float radius, posX, posY;
        uint32_t fillColor, outlineColor;
        float outlineThickness;

        iss >> type >> radius >> posX >> posY >> fillColor >> outlineColor >> outlineThickness;

        if (type == "Circle") {
            circle = std::make_shared<Circle>(radius, sf::Vector2f(posX, posY));
            circle->GetCircleShape().setFillColor(sf::Color(fillColor));
            circle->GetCircleShape().setOutlineColor(sf::Color(outlineColor));
            circle->GetCircleShape().setOutlineThickness(outlineThickness);
        }
    }

    std::shared_ptr<Shape> getResult() override {
        return circle;
    }
};
