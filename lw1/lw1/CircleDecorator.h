#ifndef CIRCLEDECORATOR_H
#define CIRCLEDECORATOR_H

#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include <cmath>
#include <fstream>
#include "MathDecorator.h"
#include "shapes.h"

class CircleDecorator : public MathDecorator
{
public:
    CircleDecorator(std::shared_ptr<Circle> shape)
        : m_shape(shape)
    {
    }

    double GetPerimeter() override
    {
        return 2 * M_PI * m_shape->GetCircleShape().getRadius();
    }

    double GetArea() override
    {
        return M_PI * std::pow(m_shape->GetCircleShape().getRadius(), 2);
    }

    void PrintData(std::ofstream& output) override
    {
        output << "P = " << GetPerimeter() << "; S = " << GetArea() << std::endl;
    }
    void Draw(sf::RenderWindow& window) override
    {
        m_shape->Draw(window);
    }
    std::string serialize() const override {
        return "";
    }
    bool Contains(const sf::Vector2f& point) const override
    {
        return m_shape->Contains(point);
    }

    sf::Vector2f GetPosition() const override
    {
        return m_shape->GetPosition();
    }
    void setPosition(const sf::Vector2f& position) override
    {
        m_shape->setPosition(position);
    }
    sf::Vector2f GetRightDownCorner() const override
    {
        return m_shape->GetRightDownCorner();
    }

    void Move(const sf::Vector2f& point) override
    {
        m_shape->Move(point);
    }

    void Select(const bool select) override
    {
        m_shape->Select(select);
    }

    bool IsSelected() const override
    {
        return m_shape->IsSelected();
    }

    bool IsGroup() const override
    {
        return m_shape->IsGroup();
    }

    void accept(Visitor& visitor) override
    {
        m_shape->accept(visitor);
    }
    std::shared_ptr<Shape> clone() const override
    {
        return m_shape->clone();
    }

private:
    std::shared_ptr<Circle> m_shape;
};

#endif