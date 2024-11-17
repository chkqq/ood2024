#pragma once
#include "Shape.h"
#include <SFML/Graphics.hpp>
#include <memory>

class Rectangle : public Shape
{
private:
    sf::RectangleShape m_rectangle;
    sf::RectangleShape m_frame;
    bool m_isSelected = false;

public:
    Rectangle(sf::Vector2f size, sf::Vector2f position);

    std::string serialize() const override;
    void Draw(sf::RenderWindow& window) override;
    bool Contains(const sf::Vector2f& point) const override;
    sf::Vector2f GetPosition() const override;
    void setPosition(const sf::Vector2f& position) override;
    void Move(const sf::Vector2f& point) override;
    sf::Vector2f GetRightDownCorner() const override;
    void Select(const bool select) override;
    bool IsSelected() const override;
    bool IsGroup() const override;
    void accept(Visitor& visitor) override;

    std::shared_ptr<Shape> clone() const override;
    sf::RectangleShape& GetRectangleShape();
};
