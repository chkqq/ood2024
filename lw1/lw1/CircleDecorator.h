#ifndef CIRCLEDECORATOR_H
#define CIRCLEDECORATOR_H

#include "ShapeDecorator.h"
#include "Circle.h"
#include <memory>

class CircleDecorator : public ShapeDecorator
{
private:
    sf::Color m_color;
    sf::Color m_outlineColor;
    float m_outlineThickness;

public:
    CircleDecorator(std::shared_ptr<Shape> shape, sf::Color color, sf::Color outlineColor, float outlineThickness)
        : ShapeDecorator(shape), m_color(color), m_outlineColor(outlineColor), m_outlineThickness(outlineThickness) {}
    void SetColor(const sf::Color& color, const sf::Color& outlineColor, float outlineThickness)
    {
        m_color = color;
        m_outlineColor = outlineColor;
        m_outlineThickness = outlineThickness;
    }
    void Draw(sf::RenderWindow& window) override
    {
        auto circle = dynamic_cast<Circle*>(m_shape.get());
        if (circle)
        {
            circle->GetCircleShape().setFillColor(m_color);
            circle->GetCircleShape().setOutlineColor(m_outlineColor);
            circle->GetCircleShape().setOutlineThickness(m_outlineThickness);
        }
        ShapeDecorator::Draw(window);
    }
};

#endif