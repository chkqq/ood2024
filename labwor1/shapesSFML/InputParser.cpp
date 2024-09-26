#include "InputParser.h"
#include "CircleShape.h"
#include "RectangleShape.h"
#include "TriangleShape.h"
#include <fstream>
#include <sstream>

std::vector<ShapeDecorator*> LoadShapesFromFile(const std::string& filename) 
{
    std::ifstream file(filename);
    std::vector<ShapeDecorator*> shapes;
    std::string line;
    while (std::getline(file, line)) 
    {
        std::istringstream iss(line);
        std::string type;
        iss >> type;
        if (type == "CIRCLE:") 
        {
            int cx, cy, r;
            char temp;
            iss.ignore(3);
            iss >> cx >> temp
                >> cy >> temp >> temp >> temp 
                >> r;
            shapes.push_back(new CircleDecorator(r, sf::Vector2f(cx, cy)));
        }
        else if (type == "RECTANGLE:") 
        {
            int x1, y1, x2, y2;
            char temp;
            iss.ignore(4);
            iss >> x1 >> temp 
                >> y1 >> temp >> temp >> temp >> temp
                >> x2 >> temp 
                >> y2;
            shapes.push_back(new RectangleDecorator(sf::Vector2f(x2 - x1, y2 - y1), sf::Vector2f(x1, y1)));
        }
        else if (type == "TRIANGLE:") 
        {
            int x1, y1, x2, y2, x3, y3;
            char temp;
            iss.ignore(4);
            iss >> x1 >> temp
                >> y1 >> temp >> temp >> temp >> temp
                >> x2 >> temp
                >> y2 >> temp >> temp >> temp >> temp 
                >> x3 >> temp
                >> y3;
            shapes.push_back(new TriangleDecorator(sf::Vector2f(x1, y1), sf::Vector2f(x2, y2), sf::Vector2f(x3, y3)));
        }
    }
    return shapes;
}

void SaveResultsToFile(const std::vector<ShapeDecorator*>& shapes, const std::string& filename) 
{
    std::ofstream file(filename);
    for (const auto& shape : shapes) 
    {
        if (dynamic_cast<CircleDecorator*>(shape))
        {
            file << "CIRCLE: P=" << shape->GetPerimeter() << "; S=" << shape->GetArea() << "\n";
        }
        else if (dynamic_cast<RectangleDecorator*>(shape)) 
        {
            file << "RECTANGLE: P=" << shape->GetPerimeter() << "; S=" << shape->GetArea() << "\n";
        }
        else if (dynamic_cast<TriangleDecorator*>(shape)) 
        {
            file << "TRIANGLE: P=" << shape->GetPerimeter() << "; S=" << shape->GetArea() << "\n";
        }
    }
}
