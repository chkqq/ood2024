#ifndef LINE_HPP
#define LINE_HPP

#include "shape.hpp"

namespace shapes
{
    class Line : public Shape 
    {
        double x1, y1, x2, y2;

    public:
        Line(const std::string& id, double x1, double y1, double x2, double y2, gfx::Color color);
        void Draw(gfx::ICanvas& canvas) override;
        void Move(double dx, double dy) override;
        std::string GetParameters() const override;
        std::string GetType() const override;
    };
}

#endif
