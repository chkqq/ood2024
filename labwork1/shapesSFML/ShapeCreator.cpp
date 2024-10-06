#include "ShapeCreator.h"
#include "CircleDecorator.h"
#include "RectangleDecorator.h"
#include "TriangleDecorator.h"

ShapeDecorator* CreateCircle(std::istringstream& iss)
{
    int cx, cy, r;
    int outlineThickness;
    int colorR, colorG, colorB;
    int outColorR, outColorG, outColorB;

    char temp;

    iss.ignore(3);
    iss >> cx >> temp
        >> cy >> temp >> temp >> temp
        >> r >> temp >> temp >> temp >> temp
        >> outlineThickness >> temp >> temp >> temp >> temp
        >> colorR >> temp
        >> colorG >> temp
        >> colorB >> temp >> temp >> temp >> temp >> temp
        >> outColorR >> temp
        >> outColorG >> temp
        >> outColorB;

    sf::Color color(colorR, colorG, colorB);
    sf::Color outlineColor(outColorR, outColorG, outColorB);
    return new CircleDecorator(new Circle(r, sf::Vector2f(cx, cy)), color, outlineColor, outlineThickness);
}

ShapeDecorator* CreateRectangle(std::istringstream& iss)
{
    int x1, y1, x2, y2;
    int outlineThickness;
    int colorR, colorG, colorB;
    int outColorR, outColorG, outColorB;

    char temp;

    iss.ignore(4);
    iss >> x1 >> temp
        >> y1 >> temp >> temp >> temp >> temp
        >> x2 >> temp
        >> y2 >> temp >> temp >> temp >> temp
        >> outlineThickness >> temp >> temp >> temp >> temp
        >> colorR >> temp
        >> colorG >> temp
        >> colorB >> temp >> temp >> temp >> temp >> temp
        >> outColorR >> temp
        >> outColorG >> temp
        >> outColorB;

    sf::Color color(colorR, colorG, colorB);
    sf::Color outlineColor(outColorR, outColorG, outColorB);
    return new RectangleDecorator(new Rectangle(sf::Vector2f(x2 - x1, y2 - y1), sf::Vector2f(x1, y1)), color, outlineColor, outlineThickness);
}

ShapeDecorator* CreateTriangle(std::istringstream& iss)
{
    int x1, y1, x2, y2, x3, y3;
    int outlineThickness;
    int colorR, colorG, colorB;
    int outColorR, outColorG, outColorB;
    char temp;

    iss.ignore(4);
    iss >> x1 >> temp
        >> y1 >> temp >> temp >> temp >> temp
        >> x2 >> temp
        >> y2 >> temp >> temp >> temp >> temp
        >> x3 >> temp
        >> y3 >> temp >> temp >> temp
        >> outlineThickness >> temp >> temp >> temp >> temp
        >> colorR >> temp
        >> colorG >> temp
        >> colorB >> temp >> temp >> temp >> temp >> temp
        >> outColorR >> temp
        >> outColorG >> temp
        >> outColorB;

    sf::Color color(colorR, colorG, colorB);
    sf::Color outlineColor(outColorR, outColorG, outColorB);
    return new TriangleDecorator(new Triangle(sf::Vector2f(x1, y1), sf::Vector2f(x2, y2), sf::Vector2f(x3, y3)), color, outlineColor, outlineThickness);
}

std::map<std::string, ShapeCreator> GetShapeFactory()
{
    return {
        {"CIRCLE:", CreateCircle},
        {"RECTANGLE:", CreateRectangle},
        {"TRIANGLE:", CreateTriangle}
    };
}
