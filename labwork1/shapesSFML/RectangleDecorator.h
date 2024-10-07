#ifndef RECTANGLEDECORATOR_H
#define RECTANGLEDECORATOR_H

#include "ShapeDecorator.h"
#include "Rectangle.h"
#include <memory>

class RectangleDecorator : public ShapeDecorator
{
private:
    sf::Color m_color;
    sf::Color m_outlineColor;
    float m_outlineThickness;

public:
    RectangleDecorator(std::shared_ptr<Shape> shape, sf::Color color, sf::Color outlineColor, float outlineThickness)
        : ShapeDecorator(shape), m_color(color), m_outlineColor(outlineColor), m_outlineThickness(outlineThickness) {}

    void Draw(sf::RenderWindow& window) override
    {
        auto rectangle = dynamic_cast<Rectangle*>(m_shape.get());
        if (rectangle)
        {
            rectangle->GetRectangleShape().setFillColor(m_color);
            rectangle->GetRectangleShape().setOutlineColor(m_outlineColor);
            rectangle->GetRectangleShape().setOutlineThickness(m_outlineThickness);
        }
        ShapeDecorator::Draw(window);
    }
};

#endif
