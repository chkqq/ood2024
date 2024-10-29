#ifndef SHAPECREATOR_H
#define SHAPECREATOR_H

#include <functional>
#include <string>
#include <sstream>
#include <map>
#include <memory>
#include "ShapeDecorator.h"

using ShapeCreator = std::function<std::shared_ptr<ShapeDecorator>(std::istringstream&)>;

std::shared_ptr<ShapeDecorator> CreateCircle(std::istringstream& iss);
std::shared_ptr<ShapeDecorator> CreateRectangle(std::istringstream& iss);
std::shared_ptr<ShapeDecorator> CreateTriangle(std::istringstream& iss);

std::map<std::string, ShapeCreator> GetShapeFactory();

#endif
