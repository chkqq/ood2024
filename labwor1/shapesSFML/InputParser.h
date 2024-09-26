#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <vector>
#include <string>
#include "ShapeDecorator.h"

std::vector<ShapeDecorator*> LoadShapesFromFile(const std::string& filename);
void SaveResultsToFile(const std::vector<ShapeDecorator*>& shapes, const std::string& filename);

#endif
