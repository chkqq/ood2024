#include "ShapeBuilder.h"
#include "Rectangle.h"
#include <sstream>

class RectangleBuilder : public ShapeBuilder {
private:
    std::shared_ptr<Rectangle> rectangle;

public:
    void buildShape(const std::string& data) override {
        std::istringstream iss(data);
        std::string type;
        float width, height, posX, posY;
        uint32_t fillColor, outlineColor;
        float outlineThickness;

        iss >> type >> width >> height >> posX >> posY >> fillColor >> outlineColor >> outlineThickness;

        if (type == "Rectangle") {
            rectangle = std::make_shared<Rectangle>(sf::Vector2f(width, height), sf::Vector2f(posX, posY));
            rectangle->GetRectangleShape().setFillColor(sf::Color(fillColor));
            rectangle->GetRectangleShape().setOutlineColor(sf::Color(outlineColor));
            rectangle->GetRectangleShape().setOutlineThickness(outlineThickness);
        }
    }

    std::shared_ptr<Shape> getResult() override {
        return rectangle;
    }
};
