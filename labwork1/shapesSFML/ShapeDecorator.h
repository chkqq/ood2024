#ifndef SHAPEDECORATOR_H
#define SHAPEDECORATOR_H

#include "Shape.h"

class ShapeDecorator : public Shape
{
protected:
    Shape* m_shape;

public:
    ShapeDecorator(Shape* shape) : m_shape(shape) {}

    void Draw(sf::RenderWindow& window) override
    {
        m_shape->Draw(window);
    }

    float GetPerimeter() const override
    {
        return m_shape->GetPerimeter();
    }

    float GetArea() const override
    {
        return m_shape->GetArea();
    }

    ~ShapeDecorator() override
    {
        delete m_shape;
    }
};

#endif
