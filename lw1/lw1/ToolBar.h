#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "ToolBarButton.h"
#include "CareTaker.h"
class ToolBar
{
private:
    std::vector<ToolBarButton> buttons;

public:
    void setupButtons(sf::Font& font);
    void handleToolbarClick(const sf::Vector2i& mousePosition, std::vector<std::shared_ptr<Shape>>& shapes, Caretaker& caretaker);
    void draw(sf::RenderWindow& window);
    const std::vector<ToolBarButton>& getButtons() const;
    bool IsMouseOverButton(const sf::Vector2i& mousePosition) const;
};
