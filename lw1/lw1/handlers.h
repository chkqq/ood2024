#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "shapes.h"
#include "Command.h"
#include "ToolBar.h"
#include "Application.h"
class Handlers {
public:
    Handlers() = default;

    void ShapesMoving(sf::RenderWindow& window, std::vector<std::shared_ptr<Shape>>& shapes, bool& isMove, Caretaker& caretaker, ToolBar& toolbar);
    void ListenEvents(sf::RenderWindow& window, std::vector<std::shared_ptr<Shape>>& shapes, bool& isMove, ToolBar& toolbar, Caretaker& caretaker);
    void DrawShapes(sf::RenderWindow& window, const std::vector<std::shared_ptr<Shape>>& shapes);

private:
    void HandleWindowClose(sf::RenderWindow& window, const sf::Event& event);
    bool HandleMousePress(sf::RenderWindow& window, const sf::Event& event, std::vector<std::shared_ptr<Shape>>& shapes, ToolBar& toolbar, Caretaker& caretaker);
    bool IsToolbarButtonClicked(const sf::Vector2i& mousePosition, ToolBar& toolbar);
    bool HandleShapeSelection(const sf::Event& event, std::vector<std::shared_ptr<Shape>>& shapes);
    bool HandleKeyPress(const sf::Event& event, std::vector<std::shared_ptr<Shape>>& shapes, Caretaker& caretaker);
    void GroupSelectedShapes(std::vector<std::shared_ptr<Shape>>& shapes);
    void RemoveAndDeselectShapes(std::vector<std::shared_ptr<Shape>>& shapes, const std::vector<int>& indices);
    void UngroupSelectedShapes(std::vector<std::shared_ptr<Shape>>& shapes);
};
