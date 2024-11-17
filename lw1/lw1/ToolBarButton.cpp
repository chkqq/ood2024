#include "ToolBarButton.h"

ToolBarButton::ToolBarButton(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color, const std::string& text, sf::Font& font, std::unique_ptr<Command> cmd)
    : command(std::move(cmd))
{
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(color);

    label.setFont(font);
    label.setString(text);
    label.setCharacterSize(16);
    label.setFillColor(sf::Color::Black);
    label.setPosition(position.x + 5, position.y + 5);
}

bool ToolBarButton::contains(const sf::Vector2i& mousePosition) const
{
    return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition));
}

void ToolBarButton::executeCommand(std::vector<std::shared_ptr<Shape>>& shapes)
{
    if (command)
        command->execute(shapes);
}

void ToolBarButton::draw(sf::RenderWindow& window)
{
    window.draw(shape);
    window.draw(label);
}

const sf::RectangleShape& ToolBarButton::getShape() const
{
    return shape;
}

sf::FloatRect ToolBarButton::getGlobalBounds() const
{
    return shape.getGlobalBounds();
}
