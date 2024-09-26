#include "ShapeCreator.h"
#include "CircleShape.h"
#include "RectangleShape.h"
#include "TriangleShape.h"

ShapeDecorator* CreateCircle(std::istringstream& iss)
{
    int cx, cy, r;
    char temp;
    iss.ignore(3);
    iss >> cx >> temp
        >> cy >> temp >> temp >> temp 
        >> r;
    return new CircleDecorator(r, sf::Vector2f(cx, cy));
}

ShapeDecorator* CreateRectangle(std::istringstream& iss)
{
    int x1, y1, x2, y2;
    char temp;
    iss.ignore(4);
    iss >> x1 >> temp 
        >> y1 >> temp >> temp >> temp >> temp
        >> x2 >> temp
        >> y2;
    return new RectangleDecorator(sf::Vector2f(x2 - x1, y2 - y1), sf::Vector2f(x1, y1));
}

ShapeDecorator* CreateTriangle(std::istringstream& iss)
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
    return new TriangleDecorator(sf::Vector2f(x1, y1), sf::Vector2f(x2, y2), sf::Vector2f(x3, y3));
}

std::map<std::string, ShapeCreator> GetShapeFactory()
{
    return {
        {"CIRCLE:", CreateCircle},
        {"RECTANGLE:", CreateRectangle},
        {"TRIANGLE:", CreateTriangle}
    };
}
