#include "ToolBar.h"
#include "Commands.h"

void ToolBar::setupButtons(sf::Font& font)
{
    buttons.emplace_back(sf::Vector2f(50, 50), sf::Vector2f(10, 10), sf::Color::Cyan, "Circle", font, std::make_unique<AddCircleCommand>());
    buttons.emplace_back(sf::Vector2f(50, 50), sf::Vector2f(72, 10), sf::Color::Cyan, "Rect", font, std::make_unique<AddRectangleCommand>());
    buttons.emplace_back(sf::Vector2f(50, 50), sf::Vector2f(134, 10), sf::Color::Cyan, "Tri", font, std::make_unique<AddTriangleCommand>());

    buttons.emplace_back(sf::Vector2f(50, 50), sf::Vector2f(196, 10), sf::Color::Green, "Fill G", font, std::make_unique<ChangeFillColorCommand>(sf::Color::Green));
    buttons.emplace_back(sf::Vector2f(50, 50), sf::Vector2f(258, 10), sf::Color::Red, "Fill R", font, std::make_unique<ChangeFillColorCommand>(sf::Color::Red));
    buttons.emplace_back(sf::Vector2f(50, 50), sf::Vector2f(320, 10), sf::Color::Yellow, "Fill Y", font, std::make_unique<ChangeFillColorCommand>(sf::Color::Yellow));

    buttons.emplace_back(sf::Vector2f(50, 50), sf::Vector2f(382, 10), sf::Color::Blue, "Out B", font, std::make_unique<ChangeOutlineColorCommand>(sf::Color::Blue));
    buttons.emplace_back(sf::Vector2f(50, 50), sf::Vector2f(444, 10), sf::Color::Black, "Out Bl", font, std::make_unique<ChangeOutlineColorCommand>(sf::Color::Black));
    buttons.emplace_back(sf::Vector2f(50, 50), sf::Vector2f(506, 10), sf::Color::Magenta, "Out M", font, std::make_unique<ChangeOutlineColorCommand>(sf::Color::Magenta));

    buttons.emplace_back(sf::Vector2f(50, 50), sf::Vector2f(568, 10), sf::Color::Cyan, "Th 1", font, std::make_unique<ChangeOutlineThicknessCommand>(0.5f));
    buttons.emplace_back(sf::Vector2f(50, 50), sf::Vector2f(630, 10), sf::Color::Cyan, "Th 3", font, std::make_unique<ChangeOutlineThicknessCommand>(3.0f));
    buttons.emplace_back(sf::Vector2f(50, 50), sf::Vector2f(692, 10), sf::Color::Cyan, "Th 5", font, std::make_unique<ChangeOutlineThicknessCommand>(5.0f));
}

void ToolBar::handleToolbarClick(const sf::Vector2i& mousePosition, std::vector<std::shared_ptr<Shape>>& shapes)
{
    for (auto& button : buttons)
    {
        if (button.contains(mousePosition))
        {
            button.executeCommand(shapes);
            break;
        }
    }
}

void ToolBar::draw(sf::RenderWindow& window)
{
    for (auto& button : buttons)
    {
        button.draw(window);
    }
}
const std::vector<ToolBarButton>& ToolBar::getButtons() const
{
    return buttons;
}