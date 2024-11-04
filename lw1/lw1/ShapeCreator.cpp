#include "ShapeCreator.h"
#include "CircleDecorator.h"
#include "RectangleDecorator.h"
#include "TriangleDecorator.h"
#include <memory>

std::shared_ptr<MathDecorator> CreateCircle(std::istringstream& iss)
{
    int cx, cy, r;
    char temp;

    iss.ignore(3);
    iss >> cx >> temp
        >> cy >> temp >> temp >> temp
        >> r;

    auto circle = std::make_shared<Circle>(r, sf::Vector2f(cx, cy));
    return std::make_shared<CircleDecorator>(circle);
}

std::shared_ptr<MathDecorator> CreateRectangle(std::istringstream& iss)
{
    int x1, y1, x2, y2;
    char temp;

    iss.ignore(4);
    iss >> x1 >> temp
        >> y1 >> temp >> temp >> temp >> temp
        >> x2 >> temp
        >> y2;

    auto rectangle = std::make_shared<Rectangle>(sf::Vector2f(x2 - x1, y2 - y1), sf::Vector2f(x1, y1));
    return std::make_shared<RectangleDecorator>(rectangle);
}

std::shared_ptr<MathDecorator> CreateTriangle(std::istringstream& iss)
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

    auto triangle = std::make_shared<Triangle>(sf::Vector2f(x1, y1), sf::Vector2f(x2, y2), sf::Vector2f(x3, y3));
    return std::make_shared<TriangleDecorator>(triangle);
}

std::map<std::string, ShapeCreator> GetShapeFactory()
{
    return {
        {"CIRCLE:", CreateCircle},
        {"RECTANGLE:", CreateRectangle},
        {"TRIANGLE:", CreateTriangle}
    };
}