#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include "ICanvas.hpp"

namespace shapes
{
    class Shape 
    {
    protected:
        std::string id;
        gfx::Color color;

    public:
        Shape(const std::string& id, gfx::Color color);
        virtual ~Shape() = default;
        virtual void Draw(gfx::ICanvas& canvas) = 0;
        virtual void MoveBy(double dx, double dy) = 0;
        gfx::Color GetColor() const;
        virtual std::string GetType() const = 0;
        virtual std::string GetParameters() const = 0;
        std::string GetID() const;
    };
}

#endif
