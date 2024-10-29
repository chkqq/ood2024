#ifndef TRIANGLEDECORATOR_H
#define TRIANGLEDECORATOR_H

#include "ShapeDecorator.h"
#include "Triangle.h"
#include <memory>

class TriangleDecorator : public ShapeDecorator
{
private:
    sf::Color m_color;
    sf::Color m_outlineColor;
    float m_outlineThickness;

public:
    TriangleDecorator(std::shared_ptr<Shape> shape, sf::Color color, sf::Color outlineColor, float outlineThickness)
        : ShapeDecorator(shape), m_color(color), m_outlineColor(outlineColor), m_outlineThickness(outlineThickness) {}
    void SetColor(const sf::Color& color, const sf::Color& outlineColor, float outlineThickness)
    {
        m_color = color;
        m_outlineColor = outlineColor;
        m_outlineThickness = outlineThickness;
    }
    void Draw(sf::RenderWindow& window) override
    {
        auto triangle = dynamic_cast<Triangle*>(m_shape.get());
        if (triangle)
        {
            triangle->GetTriangleShape().setFillColor(m_color);
            triangle->GetTriangleShape().setOutlineColor(m_outlineColor);
            triangle->GetTriangleShape().setOutlineThickness(m_outlineThickness);
        }
        ShapeDecorator::Draw(window);
    }
};

#endif
