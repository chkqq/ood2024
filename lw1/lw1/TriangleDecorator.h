#ifndef TRIANGLEDECORATOR_H
#define TRIANGLEDECORATOR_H

#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include <cmath>
#include <fstream>
#include "MathDecorator.h"
#include "Triangle.h"

class TriangleDecorator : public MathDecorator
{
public:
    TriangleDecorator(std::shared_ptr<Triangle> shape)
        : m_shape(shape)
    {
    }

    double GetPerimeter() override
    {
        sf::ConvexShape& triangle = m_shape->GetTriangleShape();
        float side1 = Distance(triangle.getPoint(0), triangle.getPoint(1));
        float side2 = Distance(triangle.getPoint(1), triangle.getPoint(2));
        float side3 = Distance(triangle.getPoint(2), triangle.getPoint(0));

        return side1 + side2 + side3;
    }

    double GetArea() override
    {
        sf::ConvexShape& triangle = m_shape->GetTriangleShape();
        // Формула для площади треугольника через координаты вершин
        float x1 = triangle.getPoint(0).x, y1 = triangle.getPoint(0).y;
        float x2 = triangle.getPoint(1).x, y2 = triangle.getPoint(1).y;
        float x3 = triangle.getPoint(2).x, y3 = triangle.getPoint(2).y;

        return std::abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0f);
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

    sf::Vector2f GetRightDownCorner() const override
    {
        return m_shape->GetRightDownCorner();
    }

    void Move(const sf::Vector2f& offset) override
    {
        m_shape->Move(offset);
    }

    void Select(bool select) override
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
    std::shared_ptr<Triangle> m_shape;

    float Distance(const sf::Vector2f& p1, const sf::Vector2f& p2) const
    {
        return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
    }
};

#endif // TRIANGLEDECORATOR_H
