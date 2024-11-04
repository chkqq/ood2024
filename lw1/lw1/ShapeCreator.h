#ifndef SHAPECREATOR_H
#define SHAPECREATOR_H

#include <functional>
#include <string>
#include <sstream>
#include <map>
#include <memory>
#include "MathDecorator.h"

using ShapeCreator = std::function<std::shared_ptr<MathDecorator>(std::istringstream&)>;

std::shared_ptr<MathDecorator> CreateCircle(std::istringstream& iss);
std::shared_ptr<MathDecorator> CreateRectangle(std::istringstream& iss);
std::shared_ptr<MathDecorator> CreateTriangle(std::istringstream& iss);

std::map<std::string, ShapeCreator> GetShapeFactory();

#endif
