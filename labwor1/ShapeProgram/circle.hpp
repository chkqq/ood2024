#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace shapes
{
    class Circle : public Shape 
    {
        double x, y, r;

    public:
        Circle(const std::string& id, double x, double y, double r, gfx::Color color);
        void Draw(gfx::ICanvas& canvas) override;
        void MoveBy(double dx, double dy) override;
        std::string GetParameters() const override;
        std::string GetType() const override;
    };
}

#endif
