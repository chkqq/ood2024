#ifndef PICTURE_HPP
#define PICTURE_HPP

#include <vector>
#include <memory>
#include <unordered_set>
#include "shape.hpp"

namespace shapes
{
    class Picture 
    {
        std::vector<std::shared_ptr<Shape>> shapes;
        std::unordered_set<std::string> shapeNames;

    public:
        void AddShape(std::shared_ptr<Shape> shape);
        void ChangeShape(const std::string& id, std::shared_ptr<Shape> newShape);
        void Move(double dx, double dy);
        void Draw(gfx::ICanvas& canvas);
        std::shared_ptr<Shape> GetShapeByID(const std::string& id);
        void ListShapes();
        bool DeleteShape(const std::string& id);
    };
}

#endif
