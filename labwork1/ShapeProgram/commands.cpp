#include "commands.hpp"
#include <sstream>
#include <iostream>

bool commands::ExecuteCommand(const std::string& command, shapes::Picture& picture) {
    std::istringstream iss(command);
    std::string cmd;
    iss >> cmd;

    if (cmd == "AddShape") {
        std::string id, shapeType, color;
        double x, y, r;
        iss >> id >> shapeType >> color >> x >> y >> r;

        if (shapeType == "circle") {
            auto shape = std::make_shared<shapes::Circle>(id, x, y, r, gfx::Color(color));
            picture.AddShape(shape);
            return true;
        }
    }
    else if (cmd == "MovePicture") {
        double dx, dy;
        iss >> dx >> dy;
        picture.Move(dx, dy);
        return true;
    }
    else if (cmd == "DrawPicture") {
        gfx::SVGCanvas canvas("output.svg");
        picture.Draw(canvas);
        return true;
    }
    else if (cmd == "MoveShape") {
        std::string id;
        double dx, dy;
        iss >> id >> dx >> dy;

        auto shape = picture.GetShapeByID(id);  // Метод для поиска фигуры по ID
        if (shape != nullptr) {
            shape->Move(dx, dy);  // Перемещаем фигуру
            return true;
        }
        else {
            std::cerr << "Shape with id " << id << " not found." << std::endl;
            return false;
        }
    }

    return false;
}
