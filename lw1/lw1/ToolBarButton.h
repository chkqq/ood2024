#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Command.h"

class ToolBarButton
{
private:
    sf::RectangleShape shape; // Графическое представление кнопки
    sf::Text label; // Метка кнопки
    std::unique_ptr<Command> command; // Команда, связанная с кнопкой

public:
    ToolBarButton(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color& color, const std::string& text, sf::Font& font, std::unique_ptr<Command> cmd)
        : command(std::move(cmd))
    {
        shape.setSize(size);
        shape.setPosition(position);
        shape.setFillColor(color);

        label.setFont(font);
        label.setString(text);
        label.setCharacterSize(16);
        label.setFillColor(sf::Color::Black);
        label.setPosition(position.x + 5, position.y + 5); // Смещение для выравнивания текста
    }

    bool contains(const sf::Vector2i& mousePosition) const
    {
        return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition));
    }

    void executeCommand(std::vector<std::shared_ptr<Shape>>& shapes)
    {
        if (command)
            command->execute(shapes);
    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(shape);
        window.draw(label);
    }

    const sf::RectangleShape& getShape() const { return shape; }

    // Новый метод для получения границ кнопки
    sf::FloatRect getGlobalBounds() const
    {
        return shape.getGlobalBounds();
    }
};
