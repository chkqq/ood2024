#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "shape.h"
#include <SFML/Graphics.hpp>
#include <memory>

class Circle : public Shape
{
private:
    sf::CircleShape m_circle;
    sf::RectangleShape m_frame;
    bool m_isSelected = false;

public:
    Circle(float radius, sf::Vector2f position);

    void Draw(sf::RenderWindow& window) override;
    std::string serialize() const override;
    bool Contains(const sf::Vector2f& point) const override;
    sf::Vector2f GetPosition() const override;
    void setPosition(const sf::Vector2f& position) override;
    sf::Vector2f GetRightDownCorner() const override;
    void Move(const sf::Vector2f& point) override;
    void Select(const bool select) override;
    bool IsSelected() const override;
    bool IsGroup() const override;
    std::shared_ptr<Shape> clone() const override;
    void accept(Visitor& visitor) override;

    sf::CircleShape& GetCircleShape();
};
