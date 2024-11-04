#include "FileManager.h"
#include "ShapeCreator.h"
#include <fstream>
#include <sstream>
#include <map>
#include <memory>

std::vector<std::shared_ptr<MathDecorator>> LoadShapesFromFile(const std::string& filename)
{
    std::map<std::string, ShapeCreator> shapeFactory = GetShapeFactory();
    std::ifstream file(filename);
    std::vector<std::shared_ptr<MathDecorator>> shapes;
    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        auto it = shapeFactory.find(type);
        if (it != shapeFactory.end())
        {
            shapes.push_back(it->second(iss));
        }
    }

    return shapes;
}

void SaveResultsToFile(const std::vector<std::shared_ptr<MathDecorator>>& shapes, const std::string& filename)
{
    std::ofstream file(filename);

    for (const auto& shape : shapes)
    {
        shape->PrintData(file);
    }
}
