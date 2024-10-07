#include "EventManager.h"
#include "ShapeGroup.h"
void HandleEvents
(
    sf::RenderWindow& window,
    std::vector<std::shared_ptr<Shape>>& shapes,
    std::vector<std::shared_ptr<Shape>>& selectedShapes,
    bool& isDragging,
    std::vector<std::shared_ptr<ShapeGroup>>& groups
)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                bool shapeFound = false;
                for (auto& shape : shapes)
                {
                    if (shape->Contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    {
                        shapeFound = true;
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                        {
                            selectedShapes.push_back(shape);
                        }
                        else
                        {
                            selectedShapes.clear();
                            selectedShapes.push_back(shape);
                        }
                        break;
                    }
                }
            }
        }
        if (event.type == sf::Event::KeyPressed && event.key.control && event.key.code == sf::Keyboard::G) {
            if (!selectedShapes.empty()) {
                auto group = std::make_shared<ShapeGroup>();
                for (const auto& shape : selectedShapes) {
                    group->AddShape(shape);
                }
                groups.push_back(group);
                selectedShapes.clear();
            }
        }
        if (event.type == sf::Event::KeyPressed && event.key.control && event.key.code == sf::Keyboard::U) {
            if (!groups.empty()) {
                for (auto& group : groups) {
                    auto shapesFromGroup = group->GetShapes();
                    selectedShapes.insert(selectedShapes.end(), shapesFromGroup.begin(), shapesFromGroup.end());
                }
                groups.clear();
            }
        }
    }
}

void HandleMouseDrag
(
    sf::RenderWindow& window,
    std::vector<std::shared_ptr<Shape>>& selectedShapes,
    bool& isDragging,
    std::vector<std::shared_ptr<ShapeGroup>>& groups
)
{
    static sf::Vector2f lastMousePosition;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (!isDragging)
        {
            isDragging = true;
            lastMousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
        }

        sf::Vector2f currentPosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
        sf::Vector2f delta = currentPosition - lastMousePosition;

        for (auto& shape : selectedShapes)
        {
            shape->Move(delta);
        }

        for (auto& group : groups)
        {
            for (auto& shapeInGroup : group->GetShapes())
            {
                shapeInGroup->Move(delta);
            }
        }

        lastMousePosition = currentPosition;
    }
    else
    {
        isDragging = false;
    }
}
