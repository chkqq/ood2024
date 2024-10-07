#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <SFML/Graphics.hpp>
#include "ShapeDecorator.h"
#include "ShapeGroup.h"

void HandleEvents
(
	sf::RenderWindow& window, 
	std::vector<std::shared_ptr<Shape>>& shapes, 
	std::vector<std::shared_ptr<Shape>>& selectedShapes, 
	bool& isDragging, std::vector<std::shared_ptr<ShapeGroup>>& groups
);
void HandleMouseDrag
(
	sf::RenderWindow& window, 
	std::vector<std::shared_ptr<Shape>>& selectedShapes, 
	bool& isDragging, std::vector<std::shared_ptr<ShapeGroup>>& groups
);

#endif
