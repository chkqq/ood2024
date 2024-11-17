#include "ToolBar.h"
#include "Commands.h"
#include "TextSaveStrategy.h"

TextSaveStrategy textSaveStrategy;
ShapeLoader loader;

void ToolBar::setupButtons(sf::Font& font)
{
    sf::Vector2f buttonSize(40, 40);
    float spacing = 5.0f;
    float startX = 10.0f; 
    float yPosition = 10.0f; 

    buttons.emplace_back(buttonSize, sf::Vector2f(startX, yPosition), sf::Color::Cyan, "Circle", font, std::make_unique<AddCircleCommand>());
    buttons.emplace_back(buttonSize, sf::Vector2f(startX + buttonSize.x + spacing, yPosition), sf::Color::Cyan, "Rect", font, std::make_unique<AddRectangleCommand>());
    buttons.emplace_back(buttonSize, sf::Vector2f(startX + 2 * (buttonSize.x + spacing), yPosition), sf::Color::Cyan, "Tri", font, std::make_unique<AddTriangleCommand>());

    buttons.emplace_back(buttonSize, sf::Vector2f(startX + 3 * (buttonSize.x + spacing), yPosition), sf::Color::Green, "Fill G", font, std::make_unique<ChangeFillColorCommand>(sf::Color::Green));
    buttons.emplace_back(buttonSize, sf::Vector2f(startX + 4 * (buttonSize.x + spacing), yPosition), sf::Color::Red, "Fill R", font, std::make_unique<ChangeFillColorCommand>(sf::Color::Red));
    buttons.emplace_back(buttonSize, sf::Vector2f(startX + 5 * (buttonSize.x + spacing), yPosition), sf::Color::Yellow, "Fill Y", font, std::make_unique<ChangeFillColorCommand>(sf::Color::Yellow));

    buttons.emplace_back(buttonSize, sf::Vector2f(startX + 6 * (buttonSize.x + spacing), yPosition), sf::Color::Blue, "Out B", font, std::make_unique<ChangeOutlineColorCommand>(sf::Color::Blue));
    buttons.emplace_back(buttonSize, sf::Vector2f(startX + 7 * (buttonSize.x + spacing), yPosition), sf::Color::Black, "Out Bl", font, std::make_unique<ChangeOutlineColorCommand>(sf::Color::Black));
    buttons.emplace_back(buttonSize, sf::Vector2f(startX + 8 * (buttonSize.x + spacing), yPosition), sf::Color::Magenta, "Out M", font, std::make_unique<ChangeOutlineColorCommand>(sf::Color::Magenta));

    buttons.emplace_back(buttonSize, sf::Vector2f(startX + 9 * (buttonSize.x + spacing), yPosition), sf::Color::Cyan, "Th 0", font, std::make_unique<ChangeOutlineThicknessCommand>(0.0f));
    buttons.emplace_back(buttonSize, sf::Vector2f(startX + 10 * (buttonSize.x + spacing), yPosition), sf::Color::Cyan, "Th 3", font, std::make_unique<ChangeOutlineThicknessCommand>(3.0f));
    buttons.emplace_back(buttonSize, sf::Vector2f(startX + 11 * (buttonSize.x + spacing), yPosition), sf::Color::Cyan, "Th 5", font, std::make_unique<ChangeOutlineThicknessCommand>(5.0f));

    buttons.emplace_back(buttonSize, sf::Vector2f(startX + 12 * (buttonSize.x + spacing), yPosition), sf::Color::Cyan, "Undo", font, std::make_unique<UndoCommand>());
    buttons.emplace_back(buttonSize, sf::Vector2f(startX + 13 * (buttonSize.x + spacing), yPosition), sf::Color::Cyan, "Save", font, std::make_unique<SaveCommand>(textSaveStrategy));

    buttons.emplace_back(buttonSize, sf::Vector2f(startX + 14 * (buttonSize.x + spacing), yPosition), sf::Color::Cyan, "Load", font, std::make_unique<LoadCommand>(loader));
}

void ToolBar::handleToolbarClick(const sf::Vector2i& mousePosition, std::vector<std::shared_ptr<Shape>>& shapes, Caretaker& caretaker)
{
    for (int i = 0; i < buttons.size(); i++)
    {
        if (buttons[i].contains(mousePosition))
        {
            if (i != 12)
                caretaker.Save(std::make_shared<Memento>(shapes));
            buttons[i].executeCommand(shapes);
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

bool ToolBar::IsMouseOverButton(const sf::Vector2i& mousePosition) const
{
    for (const auto& button : buttons)
    {
        if (button.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
        {
            return true;
        }
    }
    return false;
}