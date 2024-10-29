#include <fstream>
#include "handlers.h"

void ShapesMoving(sf::RenderWindow& window, std::vector<std::shared_ptr<Shape>>& shapes, bool& isMove)
{
    static sf::Vector2i lastMousePosition;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (!isMove)
        {
            isMove = true;
            lastMousePosition = sf::Mouse::getPosition(window);
        }
        sf::Vector2i currentPosition = sf::Mouse::getPosition(window);
        for (auto& shape : shapes)
            if (shape->IsSelected())
                shape->Move(sf::Vector2f(currentPosition - lastMousePosition));
        lastMousePosition = currentPosition;
    }
    else
        isMove = false;
}

void ListenEvents(sf::RenderWindow& window, std::vector<std::shared_ptr<Shape>>& shapes, bool& isMove)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            for (auto& shape : shapes)
            {
                if (shape->Contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                    shape->Select(true);
                else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                    shape->Select(false);
            }
        }

        if (event.type == sf::Event::KeyPressed && event.key.control && event.key.code == sf::Keyboard::G)
        {
            auto group = std::make_shared<Group>();
            std::vector<int> tempShapes;
            for (int i = 0; i < shapes.size(); i++)
            {
                if (shapes[i]->IsSelected())
                {
                    group->AddShape(shapes[i]);
                    tempShapes.push_back(i);
                }
            }
            for (int i = tempShapes.size(); i-- > 0;)
            {
                shapes[tempShapes[i]]->Select(false);
                shapes.erase(shapes.begin() + tempShapes[i]);
            }
            if (!group->IsEmpty())
            {
                group->MakeFrame();
                shapes.push_back(group);
            }
        }

        if (event.type == sf::Event::KeyPressed && event.key.control && event.key.code == sf::Keyboard::U)
        {
            for (int i = 0; i < shapes.size(); i++)
            {
                if (shapes[i]->IsSelected() && shapes[i]->IsGroup())
                {
                    auto group = std::dynamic_pointer_cast<Group>(shapes[i]);
                    if (group && !group->IsEmpty())
                    {
                        auto shapesFromGroup = group->GetShapes();
                        shapes.push_back(shapesFromGroup.back());
                        group->DeleteShape(shapesFromGroup.back());
                        group->MakeFrame();
                    }
                    if (group->IsEmpty())
                    {
                        shapes.erase(shapes.begin() + i);
                    }
                }
            }
        }
        ShapesMoving(window, shapes, isMove);
    }
}
void DrawShapes(sf::RenderWindow& window, std::vector<std::shared_ptr<Shape>>& shapes)
{
    for (auto shape : shapes)
        shape->Draw(window);
};
