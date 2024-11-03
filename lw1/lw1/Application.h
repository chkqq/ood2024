#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Shape.h"
#include "Command.h"
#include "ToolBar.h"

class Application
{
private:
    static std::shared_ptr<Application> instance; // Изменено на std::shared_ptr
    sf::RenderWindow window;
    std::vector<std::shared_ptr<Shape>> shapes;
    bool isMove;
    ToolBar toolbar;
    std::vector<std::unique_ptr<Command>> commands;

    Application()
        : window(sf::VideoMode(800, 600), "Graphics Editor"), isMove(false)
    {
    }

public:
    static std::shared_ptr<Application> getInstance()
    {
        if (!instance)
            instance = std::shared_ptr<Application>(new Application()); // Используем std::shared_ptr
        return instance;
    }

    void run();
};
