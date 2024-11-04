#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>
#include "MathDecorator.h"

std::vector<std::shared_ptr<MathDecorator>> LoadShapesFromFile(const std::string& filename);
void SaveResultsToFile(const std::vector<std::shared_ptr<MathDecorator>>& shapes, const std::string& filename);

#endif
