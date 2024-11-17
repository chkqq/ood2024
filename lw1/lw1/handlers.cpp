#include "handlers.h"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "CareTaker.h"
#include "Application.h"

void Handlers::ShapesMoving(sf::RenderWindow& window, std::vector<std::shared_ptr<Shape>>& shapes, bool& isMove, Caretaker& caretaker, ToolBar& toolbar)
{
    sf::Vector2i currentPosition = sf::Mouse::getPosition(window);
    
    if (toolbar.IsMouseOverButton(currentPosition))
    {
        isMove = false;
        return;
    }

    static sf::Vector2i lastMousePosition;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (!isMove)
        {
            isMove = true;
            lastMousePosition = sf::Mouse::getPosition(window);
            caretaker.Save(std::make_shared<Memento>(shapes));
        }
        sf::Vector2i currentPosition = sf::Mouse::getPosition(window);
        for (auto& shape : shapes)
        {
            if (shape->IsSelected())
            {
                shape->Move(sf::Vector2f(currentPosition - lastMousePosition));
            }
        }
        lastMousePosition = currentPosition;
    }
    else
    {
        isMove = false;
    }
}



void Handlers::HandleWindowClose(sf::RenderWindow& window, const sf::Event& event)
{
    if (event.type == sf::Event::Closed)
    {
        window.close();
    }
}

bool Handlers::HandleMousePress(sf::RenderWindow& window, const sf::Event& event, std::vector<std::shared_ptr<Shape>>& shapes, ToolBar& toolbar, Caretaker& caretaker)
{
    bool changed = false;

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        toolbar.handleToolbarClick(mousePosition, shapes, caretaker);

        if (!IsToolbarButtonClicked(mousePosition, toolbar))
        {
            changed = HandleShapeSelection(event, shapes);
        }
    }
    return changed;
}

bool Handlers::IsToolbarButtonClicked(const sf::Vector2i& mousePosition, ToolBar& toolbar)
{
    for (const auto& button : toolbar.getButtons())
    {
        if (button.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
        {
            return true;
        }
    }
    return false;
}

bool Handlers::HandleShapeSelection(const sf::Event& event, std::vector<std::shared_ptr<Shape>>& shapes)
{
    bool changed = false;
    bool selectionMade = false;

    for (auto it = shapes.rbegin(); it != shapes.rend(); ++it)
    {
        auto& shape = *it;
        bool wasSelected = shape->IsSelected();

        if (!selectionMade && shape->Contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
        {
            shape->Select(true);
            selectionMade = true;
            changed = true;
        }
        else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        {
            shape->Select(false);
            changed = changed || wasSelected;
        }
    }

    return changed;
}

bool Handlers::HandleKeyPress(const sf::Event& event, std::vector<std::shared_ptr<Shape>>& shapes, Caretaker& caretaker)
{
    if (event.type == sf::Event::KeyPressed && event.key.control)
    {
        if (event.key.code == sf::Keyboard::G)
        {
            caretaker.Save(std::make_shared<Memento>(shapes));
            GroupSelectedShapes(shapes);
            return true;
        }
        else if (event.key.code == sf::Keyboard::U)
        {
            caretaker.Save(std::make_shared<Memento>(shapes));
            UngroupSelectedShapes(shapes);
            return true;
        }
    }
    return false;
}

void Handlers::GroupSelectedShapes(std::vector<std::shared_ptr<Shape>>& shapes)
{
    auto group = std::make_shared<Group>();
    std::vector<int> selectedShapeIndices;

    for (int i = 0; i < shapes.size(); ++i)
    {
        if (shapes[i]->IsSelected())
        {
            group->AddShape(shapes[i]);
            selectedShapeIndices.push_back(i);
        }
    }

    RemoveAndDeselectShapes(shapes, selectedShapeIndices);

    if (!group->IsEmpty())
    {
        group->MakeFrame();
        shapes.push_back(group);
    }
}

void Handlers::RemoveAndDeselectShapes(std::vector<std::shared_ptr<Shape>>& shapes, const std::vector<int>& indices)
{
    for (int i = indices.size(); i-- > 0;)
    {
        shapes[indices[i]]->Select(false);
        shapes.erase(shapes.begin() + indices[i]);
    }
}

void Handlers::UngroupSelectedShapes(std::vector<std::shared_ptr<Shape>>& shapes)
{
    for (int i = 0; i < shapes.size(); ++i)
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

void Handlers::ListenEvents(sf::RenderWindow& window, std::vector<std::shared_ptr<Shape>>& shapes, bool& isMove, ToolBar& toolbar, Caretaker& caretaker)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        HandleWindowClose(window, event);
        HandleMousePress(window, event, shapes, toolbar, caretaker);
        HandleKeyPress(event, shapes, caretaker);
    }
}

void Handlers::DrawShapes(sf::RenderWindow& window, const std::vector<std::shared_ptr<Shape>>& shapes)
{
    for (const auto& shape : shapes)
        shape->Draw(window);
}
