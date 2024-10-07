#ifndef SELECTION_DECORATOR_H
#define SELECTION_DECORATOR_H

#include "ShapeDecorator.h"

class SelectionDecorator : public ShapeDecorator
{
public:
    SelectionDecorator(std::shared_ptr<Shape> shape);
    void Draw(sf::RenderWindow& window) override;
};

#endif
