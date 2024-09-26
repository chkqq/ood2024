#ifndef SHAPEMANAGER_H
#define SHAPEMANAGER_H

#include <vector>
#include "ShapeDecorator.h"

void DrawShapes(sf::RenderWindow& window, const std::vector<ShapeDecorator*>& shapes);
void CleanUpShapes(std::vector<ShapeDecorator*>& shapes);

#endif
