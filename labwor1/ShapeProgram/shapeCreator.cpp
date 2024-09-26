#include "shapeCreator.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "line.hpp"
#include "text.hpp"
#include "color.hpp"

namespace commands {

    std::shared_ptr<shapes::Shape> CreateShape(const std::string& shapeType, const std::string& id, std::istringstream& iss, const std::string& color)
    {
        if (shapeType == "circle")
        {
            double x, y, r;
            iss >> x >> y >> r;
            return std::make_shared<shapes::Circle>(id, x, y, r, gfx::Color(color));
        }
        if (shapeType == "rectangle")
        {
            double left, top, width, height;
            iss >> left >> top >> width >> height;
            return std::make_shared<shapes::Rectangle>(id, left, top, width, height, gfx::Color(color));
        }
        if (shapeType == "triangle")
        {
            double x1, y1, x2, y2, x3, y3;
            iss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
            return std::make_shared<shapes::Triangle>(id, x1, y1, x2, y2, x3, y3, gfx::Color(color));
        }
        if (shapeType == "line")
        {
            double x1, y1, x2, y2;
            iss >> x1 >> y1 >> x2 >> y2;
            return std::make_shared<shapes::Line>(id, x1, y1, x2, y2, gfx::Color(color));
        }
        if (shapeType == "text")
        {
            double left, top, fontSize;
            std::string text;
            iss >> left >> top >> fontSize;
            std::getline(iss, text);
            return std::make_shared<shapes::Text>(id, left, top, fontSize, text, gfx::Color(color));
        }
        return nullptr;
    }

}