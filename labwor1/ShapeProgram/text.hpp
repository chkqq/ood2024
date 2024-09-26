#ifndef TEXT_HPP
#define TEXT_HPP

#include "shape.hpp"

namespace shapes
{
    class Text : public Shape 
    {
        double left, top, fontSize;
        std::string content;

    public:
        Text(const std::string& id, double left, double top, double fontSize, const std::string& content, gfx::Color color);
        void Draw(gfx::ICanvas& canvas) override;
        void MoveBy(double dx, double dy) override;
        std::string GetParameters() const override;
        std::string GetType() const override;
    };
}

#endif
