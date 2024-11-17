#pragma once
#include "Shape.h"
#include <SFML/Graphics.hpp>

class Triangle : public Shape
{
private:
    sf::ConvexShape m_triangle;
    sf::RectangleShape m_frame;
    bool m_isSelected = false;

public:
    Triangle(const sf::Vector2f& point1, const sf::Vector2f& point2, const sf::Vector2f& point3);

    void UpdateFrame();
    void Draw(sf::RenderWindow& window) override;
    std::string serialize() const override;
    bool Contains(const sf::Vector2f& point) const override;
    sf::Vector2f GetPosition() const override;
    void setPosition(const sf::Vector2f& position) override;
    void Move(const sf::Vector2f& offset) override;
    sf::Vector2f GetRightDownCorner() const override;
    std::shared_ptr<Shape> clone() const override;
    void Select(bool select) override;
    bool IsSelected() const override;
    bool IsGroup() const override;
    void accept(Visitor& visitor) override;

    sf::ConvexShape& GetTriangleShape();
};
