#include "handlers.h"
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

void Handlers::ShapesMoving(sf::RenderWindow& window, std::vector<std::shared_ptr<Shape>>& shapes, bool& isMove)
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

void Handlers::HandleWindowClose(sf::RenderWindow& window, const sf::Event& event)
{
    if (event.type == sf::Event::Closed)
    {
        window.close();
    }
}

void Handlers::HandleMousePress(sf::RenderWindow& window, const sf::Event& event, std::vector<std::shared_ptr<Shape>>& shapes, ToolBar& toolbar)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        toolbar.handleToolbarClick(mousePosition, shapes);

        if (!IsToolbarButtonClicked(mousePosition, toolbar))
        {
            HandleShapeSelection(event, shapes);
        }
    }
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

void Handlers::HandleShapeSelection(const sf::Event& event, std::vector<std::shared_ptr<Shape>>& shapes)
{
    for (auto& shape : shapes)
    {
        if (shape->Contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
        {
            shape->Select(true);
        }
        else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        {
            shape->Select(false);
        }
    }
}

void Handlers::HandleKeyPress(const sf::Event& event, std::vector<std::shared_ptr<Shape>>& shapes)
{
    if (event.type == sf::Event::KeyPressed && event.key.control)
    {
        if (event.key.code == sf::Keyboard::G)
        {
            GroupSelectedShapes(shapes);
        }
        else if (event.key.code == sf::Keyboard::U)
        {
            UngroupSelectedShapes(shapes);
        }
    }
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

void Handlers::ListenEvents(sf::RenderWindow& window, std::vector<std::shared_ptr<Shape>>& shapes, bool& isMove, ToolBar& toolbar)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        HandleWindowClose(window, event);
        HandleMousePress(window, event, shapes, toolbar);
        HandleKeyPress(event, shapes);
    }
}

void Handlers::DrawShapes(sf::RenderWindow& window, const std::vector<std::shared_ptr<Shape>>& shapes)
{
    for (const auto& shape : shapes)
        shape->Draw(window);
}
