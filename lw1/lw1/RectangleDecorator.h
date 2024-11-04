#ifndef SQUAREDECORATOR_H
#define SQUAREDECORATOR_H

#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include <cmath>
#include <fstream>
#include "MathDecorator.h"
#include "Rectangle.h"

class RectangleDecorator : public MathDecorator
{
public:
    RectangleDecorator(std::shared_ptr<Rectangle> shape)
        : m_shape(shape)
    {
    }

    double GetPerimeter() override
    {
        float side = m_shape->GetRectangleShape().getSize().x;
        return 4 * side;
    }

    double GetArea() override
    {
        float side = m_shape->GetRectangleShape().getSize().x;
        return side * side;
    }

    void PrintData(std::ofstream& output) override
    {
        output << "P = " << GetPerimeter() << "; S = " << GetArea() << std::endl;
    }  
    void Draw(sf::RenderWindow& window) override
    {
        m_shape->Draw(window);
    }

    bool Contains(const sf::Vector2f& point) const override
    {
        return m_shape->Contains(point);
    }

    sf::Vector2f GetPosition() const override
    {
        return m_shape->GetPosition();
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


private:
    std::shared_ptr<Rectangle> m_shape;
};

#endif // SQUAREDECORATOR_H
