#pragma once

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "shapes.h"
#include "Command.h"
#include "ToolBar.h"

class Handlers {
public:
    Handlers() = default;

    void ShapesMoving(sf::RenderWindow& window, std::vector<std::shared_ptr<Shape>>& shapes, bool& isMove);
    void ListenEvents(sf::RenderWindow& window, std::vector<std::shared_ptr<Shape>>& shapes, bool& isMove, ToolBar& toolbar);
    void DrawShapes(sf::RenderWindow& window, const std::vector<std::shared_ptr<Shape>>& shapes);

private:
    void HandleWindowClose(sf::RenderWindow& window, const sf::Event& event);
    void HandleMousePress(sf::RenderWindow& window, const sf::Event& event, std::vector<std::shared_ptr<Shape>>& shapes, ToolBar& toolbar);
    bool IsToolbarButtonClicked(const sf::Vector2i& mousePosition, ToolBar& toolbar);
    void HandleShapeSelection(const sf::Event& event, std::vector<std::shared_ptr<Shape>>& shapes);
    void HandleKeyPress(const sf::Event& event, std::vector<std::shared_ptr<Shape>>& shapes);
    void GroupSelectedShapes(std::vector<std::shared_ptr<Shape>>& shapes);
    void RemoveAndDeselectShapes(std::vector<std::shared_ptr<Shape>>& shapes, const std::vector<int>& indices);
    void UngroupSelectedShapes(std::vector<std::shared_ptr<Shape>>& shapes);
};
