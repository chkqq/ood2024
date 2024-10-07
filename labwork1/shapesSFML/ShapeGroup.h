#ifndef SHAPE_GROUP_H
#define SHAPE_GROUP_H

#include <vector>
#include <memory>
#include "Shape.h"

class ShapeGroup : public Shape
{
private:
    std::vector<std::shared_ptr<Shape>> m_shapes;

public:
    void AddShape(std::shared_ptr<Shape> shape);
    void Draw(sf::RenderWindow& window) override;
    bool Contains(const sf::Vector2f& point) const override;
    void Move(const sf::Vector2f& delta) override;
    sf::FloatRect GetBounds() const override;
    float GetPerimeter() const override;
    float GetArea() const override;
};

#endif