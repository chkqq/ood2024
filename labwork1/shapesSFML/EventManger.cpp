#include "EventManager.h"
#include "ShapeDecorator.h"
void HandleEvents(sf::RenderWindow& window, std::vector<std::shared_ptr<Shape>>& shapes, std::vector<std::shared_ptr<Shape>>& selectedShapes, bool& isDragging)
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
                for (auto& shape : shapes)
                {
                    if (shape->Contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    {
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                        {
                            selectedShapes.push_back(shape);
                        }
                        else
                        {
                            selectedShapes.clear();
                            selectedShapes.push_back(shape);
                        }
                    }
                }
            }
        }
    }
}


void HandleMouseDrag(sf::RenderWindow& window, std::vector<std::shared_ptr<Shape>>& selectedShapes, bool& isDragging)
{
    static sf::Vector2f lastMousePosition;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (!isDragging)
        {
            isDragging = true;
            lastMousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
        }

        sf::Vector2f currentPosition = sf::Vector2f(sf::Mouse::getPosition(window));
        sf::Vector2f delta = currentPosition - lastMousePosition;

        for (auto& shape : selectedShapes)
        {
            shape->Move(delta);
        }

        lastMousePosition = currentPosition;
    }
    else
    {
        isDragging = false;
    }
}
