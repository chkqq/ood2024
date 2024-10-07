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
#include <memory>

std::vector<std::shared_ptr<Shape>> LoadShapesFromFile(const std::string& filename)
{
    std::map<std::string, ShapeCreator> shapeFactory = GetShapeFactory();
    std::ifstream file(filename);
    std::vector<std::shared_ptr<Shape>> shapes;
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

void SaveResultsToFile(const std::vector<std::shared_ptr<Shape>>& shapes, const std::string& filename)
{
    std::map<std::string, std::function<bool(const std::shared_ptr<Shape>&)>> shapeMap = {
        {"CIRCLE:", [](const std::shared_ptr<Shape>& shape) { return dynamic_cast<const CircleDecorator*>(shape.get()) != nullptr; }},
        {"RECTANGLE:", [](const std::shared_ptr<Shape>& shape) { return dynamic_cast<const RectangleDecorator*>(shape.get()) != nullptr; }},
        {"TRIANGLE:", [](const std::shared_ptr<Shape>& shape) { return dynamic_cast<const TriangleDecorator*>(shape.get()) != nullptr; }}
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
