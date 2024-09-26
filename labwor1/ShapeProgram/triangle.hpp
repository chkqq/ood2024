#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

namespace shapes 
{
    class Triangle : public Shape
    {
        double x1, y1, x2, y2, x3, y3;

    public:
        Triangle(const std::string& id, double x1, double y1, double x2, double y2, double x3, double y3, gfx::Color color);
        void Draw(gfx::ICanvas& canvas) override;
        void MoveBy(double dx, double dy) override;
        std::string GetParameters() const override;
        std::string GetType() const override;
    };
}

#endif
