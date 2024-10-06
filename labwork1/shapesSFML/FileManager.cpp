#include "FileManager.h"
#include "ShapeCreator.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "CircleDecorator.h"
#include "RectangleDecorator.h"
#include "TriangleDecorator.h"
#include <fstream>
#include <sstream>
#include <map>

std::vector<ShapeDecorator*> LoadShapesFromFile(const std::string& filename)
{
    std::map<std::string, ShapeCreator> shapeFactory = GetShapeFactory();
    std::ifstream file(filename);
    std::vector<ShapeDecorator*> shapes;
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

void SaveResultsToFile(const std::vector<ShapeDecorator*>& shapes, const std::string& filename)
{
    std::map<std::string, std::function<bool(const ShapeDecorator*)>> shapeMap = {
        {"CIRCLE:", [](const ShapeDecorator* shape) { return dynamic_cast<const CircleDecorator*>(shape) != nullptr; }},
        {"RECTANGLE:", [](const ShapeDecorator* shape) { return dynamic_cast<const RectangleDecorator*>(shape) != nullptr; }},
        {"TRIANGLE:", [](const ShapeDecorator* shape) { return dynamic_cast<const TriangleDecorator*>(shape) != nullptr; }}
    };

    std::ofstream file(filename);

    for (const auto& shape : shapes)
    {
        for (const auto& pair : shapeMap)   
        {
            if (pair.second(shape))
            {
                file << pair.first << " P=" << shape->GetPerimeter() << "; S=" << shape->GetArea() << "\n";
                break;
            }
        }
    }
}
