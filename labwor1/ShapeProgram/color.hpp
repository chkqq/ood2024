#ifndef COLOR_HPP
#define COLOR_HPP

#include <string>

namespace gfx 
{
    class Color
    {
    public:
        std::string value;
        Color(const std::string& val = "#000000") : value(val) {}
    };

}

#endif
