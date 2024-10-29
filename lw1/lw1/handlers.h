#pragma once
#include "shapes.h"


void ShapesMoving(sf::RenderWindow& window, std::vector<std::shared_ptr<Shape>>& shapes, bool& isMove);
void ListenEvents(sf::RenderWindow& window, std::vector<std::shared_ptr<Shape>>& shapes, bool& isMove);
void DrawShapes(sf::RenderWindow& window, std::vector<std::shared_ptr<Shape>>& shapes);