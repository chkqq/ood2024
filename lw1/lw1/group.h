#pragma once
#include "Shape.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class Group : public Shape
{
protected:
    std::vector<std::shared_ptr<Shape>> m_group;
    sf::RectangleShape m_frame;
    bool m_isSelected = true;

public:
    void MakeFrame();
    void AddShape(std::shared_ptr<Shape> shape);
    void DeleteShape(std::shared_ptr<Shape> shape);
    std::shared_ptr<Shape> clone() const override;
    std::vector<std::shared_ptr<Shape>> GetShapes();
    bool IsEmpty() const;

    void Draw(sf::RenderWindow& window) override;
    std::string serialize() const override;
    bool Contains(const sf::Vector2f& point) const override;

    sf::Vector2f GetPosition() const override;
    void setPosition(const sf::Vector2f& position) override;
    sf::Vector2f GetRightDownCorner() const override;
    void Move(const sf::Vector2f& offset) override;
    void accept(Visitor& visitor) override;
    void Select(bool select) override;
    bool IsSelected() const override;
    bool IsGroup() const override;
};
