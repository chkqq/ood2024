#ifndef SHAPECREATOR_H
#define SHAPECREATOR_H

#include <functional>
#include <string>
#include <sstream>
#include <map>
#include "ShapeDecorator.h"

using ShapeCreator = std::function<ShapeDecorator* (std::istringstream&)>;

ShapeDecorator* CreateCircle(std::istringstream& iss);
ShapeDecorator* CreateRectangle(std::istringstream& iss);
ShapeDecorator* CreateTriangle(std::istringstream& iss);

std::map<std::string, ShapeCreator> GetShapeFactory();

#endif
