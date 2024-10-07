#ifndef SHAPE_DECORATOR_H
#define SHAPE_DECORATOR_H

#include "Shape.h"

class ShapeDecorator : public Shape
{
protected:
    std::shared_ptr<Shape> m_shape;

public:
    ShapeDecorator(std::shared_ptr<Shape> shape);
    void Draw(sf::RenderWindow& window) override;
    bool Contains(const sf::Vector2f& point) const override;
    void Move(const sf::Vector2f& delta) override;
    sf::FloatRect GetBounds() const override;
    float GetPerimeter() const override;
    float GetArea() const override;
};

#endif // SHAPE_DECORATOR_H
