#include "Application.h"
#include "handlers.h"

std::shared_ptr<Application> Application::instance = nullptr;

void Application::run()
{
    sf::Font font;
    if (!font.loadFromFile("E:/edu/ood/ood2024/arialmt.ttf"))
    {
        throw std::runtime_error("Failed to load font");
    }

    toolbar.setupButtons(font);
    Handlers handlers;

    while (window.isOpen())
    {
        handlers.ListenEvents(window, shapes, isMove, toolbar);
        handlers.ShapesMoving(window, shapes, isMove);
        window.clear(sf::Color::White);
        toolbar.draw(window);
        handlers.DrawShapes(window, shapes);
        window.display();
    }
}
