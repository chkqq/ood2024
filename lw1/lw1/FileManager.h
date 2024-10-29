#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>
#include "ShapeDecorator.h"

std::vector<std::shared_ptr<Shape>> LoadShapesFromFile(const std::string& filename);
void SaveResultsToFile(const std::vector<std::shared_ptr<Shape>>& shapes, const std::string& filename);

#endif