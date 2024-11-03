#pragma once
#include <vector>
#include <memory>
#include "Shape.h"
#include <SFML/Graphics.hpp>
class Command
{
public:
    virtual void execute(std::vector<std::shared_ptr<Shape>>& shapes) = 0;
    virtual ~Command() = default;
};