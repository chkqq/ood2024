#ifndef MATHDECORATOR_H
#define MATHDECORATOR_H

#include <SFML/Graphics.hpp>
#include "Shape.h"
#include <fstream>
class MathDecorator : public Shape
{
public:
	virtual double GetPerimeter() = 0;
	virtual double GetArea() = 0;
	virtual void PrintData(std::ofstream& output) = 0;
	
    void Draw(sf::RenderWindow& window) override;
    std::string serialize() const override;
    bool Contains(const sf::Vector2f& point) const override;
    sf::Vector2f GetPosition() const override;
    void setPosition(const sf::Vector2f& position) override;
    sf::Vector2f GetRightDownCorner() const override;
    void Move(const sf::Vector2f& offset) override;
    void Select(bool select) override;
    bool IsSelected() const override;
    bool IsGroup() const override;
    void accept(Visitor& visitor) override;
    std::shared_ptr<Shape> clone() const override;
private:
    std::shared_ptr<Shape> m_shape;
};

#endif