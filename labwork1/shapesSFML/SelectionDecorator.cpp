#include "SelectionDecorator.h"

SelectionDecorator::SelectionDecorator(std::shared_ptr<Shape> shape)
    : ShapeDecorator(shape)
{}

void SelectionDecorator::Draw(sf::RenderWindow& window)
{
    ShapeDecorator::Draw(window);

    sf::FloatRect bounds = m_shape->GetBounds();
    sf::RectangleShape selectionRect(sf::Vector2f(bounds.width, bounds.height));
    selectionRect.setPosition(bounds.left, bounds.top);
    selectionRect.setFillColor(sf::Color::Transparent);
    selectionRect.setOutlineColor(sf::Color::Red);
    selectionRect.setOutlineThickness(2);
    window.draw(selectionRect);
}
