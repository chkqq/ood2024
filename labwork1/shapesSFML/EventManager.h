#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <SFML/Graphics.hpp>
#include "ShapeDecorator.h"

void HandleEvents(sf::RenderWindow& window, std::vector<std::shared_ptr<Shape>>& shapes, std::vector<std::shared_ptr<Shape>>& selectedShapes, bool& isDragging);
void HandleMouseDrag(sf::RenderWindow& window, std::vector<std::shared_ptr<Shape>>& selectedShapes, bool& isDragging);

#endif
