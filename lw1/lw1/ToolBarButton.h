#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Command.h"

class ToolBarButton
{
private:
    sf::RectangleShape shape;
    sf::Text label;
    std::unique_ptr<Command> command;

public:
    ToolBarButton(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color, const std::string& text, sf::Font& font, std::unique_ptr<Command> cmd);
    bool contains(const sf::Vector2i& mousePosition) const;
    void executeCommand(std::vector<std::shared_ptr<Shape>>& shapes);
    void draw(sf::RenderWindow& window);
    const sf::RectangleShape& getShape() const;
    sf::FloatRect getGlobalBounds() const;
};
