#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Shape.h"
#include "Command.h"
#include "ToolBar.h"
#include "CareTaker.h"
class Application
{
private:
    static std::shared_ptr<Application> instance;
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
    Caretaker caretaker;
    static std::shared_ptr<Application> getInstance()
    {
        if (!instance)
            instance = std::shared_ptr<Application>(new Application());
        return instance;
    }

    void run();

    void Undo();
    std::shared_ptr<Memento> Save();
};
