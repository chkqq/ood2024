#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace shapes 
{
    class Rectangle : public Shape
    {
        double left, top, width, height;

    public:
        Rectangle(const std::string& id, double left, double top, double width, double height, gfx::Color color);
        void Draw(gfx::ICanvas& canvas) override;
        void Move(double dx, double dy) override;
        std::string GetParameters() const override;
        std::string GetType() const override;
    };
}

#endif 
