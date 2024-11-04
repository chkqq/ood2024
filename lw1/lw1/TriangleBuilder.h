#include "ShapeBuilder.h"
#include "Triangle.h"
#include <sstream>

class TriangleBuilder : public ShapeBuilder {
private:
    std::shared_ptr<Triangle> triangle;

public:
    void buildShape(const std::string& data) override {
        std::istringstream iss(data);
        std::string type;
        float x1, y1, x2, y2, x3, y3;
        uint32_t fillColor, outlineColor;
        float outlineThickness;

        iss >> type >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> fillColor >> outlineColor >> outlineThickness;

        if (type == "Triangle") {
            triangle = std::make_shared<Triangle>(sf::Vector2f(x1, y1), sf::Vector2f(x2, y2), sf::Vector2f(x3, y3));
            triangle->GetTriangleShape().setFillColor(sf::Color(fillColor));
            triangle->GetTriangleShape().setOutlineColor(sf::Color(outlineColor));
            triangle->GetTriangleShape().setOutlineThickness(outlineThickness);
        }
    }

    std::shared_ptr<Shape> getResult() override {
        return triangle;
    }
};
