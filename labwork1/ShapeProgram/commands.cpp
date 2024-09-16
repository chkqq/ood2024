#include "commands.hpp"
#include <sstream>
#include <iostream>

bool commands::ExecuteCommand(const std::string& command, shapes::Picture& picture) {
    std::istringstream iss(command);
    std::string cmd;
    iss >> cmd;

    if (cmd == "AddShape") {
        std::string id, shapeType, color;
        iss >> id >> color >> shapeType;

        if (shapeType == "circle") {
            double x, y, r;
            iss >> x >> y >> r;
            auto shape = std::make_shared<shapes::Circle>(id, x, y, r, gfx::Color(color));
            picture.AddShape(shape);
            return true;
        }
        if (shapeType == "rectangle") {
            double left, top, width, height;
            iss >>  left >> top >> width >> height;
            auto shape = std::make_shared<shapes::Rectangle>(id, left, top, width, height, gfx::Color(color));
            picture.AddShape(shape);
            return true;
        }
        else if (shapeType == "triangle") {
            double x1, y1, x2, y2, x3, y3;
            iss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
            auto shape = std::make_shared<shapes::Triangle>(id, x1, y1, x2, y2, x3, y3, gfx::Color(color));
            picture.AddShape(shape);
            return true;
        }
        else if (shapeType == "line") {
            double x1, y1, x2, y2;
            iss >> x1 >> y1 >> x2 >> y2;
            auto shape = std::make_shared<shapes::Line>(id, x1, y1, x2, y2, gfx::Color(color));
            picture.AddShape(shape);
            return true;
        }
        else if (shapeType == "text") {
            double left, top, fontSize;
            std::string text;
            iss >> left >> top >> fontSize;
            std::getline(iss, text);
            auto shape = std::make_shared<shapes::Text>(id, left, top, fontSize, text, gfx::Color(color));
            picture.AddShape(shape);
            return true;
        }

    }
    if (cmd == "AddShape") {
        std::string id, shapeType, color;
        iss >> id >> color >> shapeType;

        if (picture.GetShapeByID(id) != nullptr) {
            std::cerr << "Shape with id '" << id << "' already exists. Use ChangeShape to modify the existing shape." << std::endl;
            return false;
        }

        // Логика создания фигуры, как была ранее...

    }
    else if (cmd == "ChangeShape") {
        std::string id, shapeType, color;
        iss >> id >> color >> shapeType;

        auto oldShape = picture.GetShapeByID(id);
        //if (oldShape == nullptr) {
        //    std::cerr << "Shape with id '" << id << "' not found." << std::endl;
        //    return false;
        //}

        // Логика изменения фигуры
        std::shared_ptr<shapes::Shape> newShape;

        if (shapeType == "circle") {
            double x, y, r;
            iss >> x >> y >> r;
            newShape = std::make_shared<shapes::Circle>(id, x, y, r, gfx::Color(color));
        }
        else if (shapeType == "rectangle") {
            double left, top, width, height;
            iss >> left >> top >> width >> height;
            newShape = std::make_shared<shapes::Rectangle>(id, left, top, width, height, gfx::Color(color));
        }
        else if (shapeType == "triangle") {
            double x1, y1, x2, y2, x3, y3;
            iss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
            newShape = std::make_shared<shapes::Triangle>(id, x1, y1, x2, y2, x3, y3, gfx::Color(color));
        }
        else if (shapeType == "line") {
            double x1, y1, x2, y2;
            iss >> x1 >> y1 >> x2 >> y2;
            newShape = std::make_shared<shapes::Line>(id, x1, y1, x2, y2, gfx::Color(color));
        }
        else if (shapeType == "text") {
            double left, top, fontSize;
            std::string text;
            iss >> left >> top >> fontSize;
            std::getline(iss, text);
            newShape = std::make_shared<shapes::Text>(id, left, top, fontSize, text, gfx::Color(color));
        }

        if (newShape) {
            picture.ChangeShape(id, newShape);
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
    else if (cmd == "DeleteShape") {
        std::string id;
        iss >> id;

        if (picture.DeleteShape(id)) {
            std::cout << "Shape with id " << id << " deleted successfully." << std::endl;
            return true;
        }
        else {
            std::cerr << "Shape with id " << id << " not found." << std::endl;
            return false;
        }
    }
    else if (cmd == "List") {
        picture.ListShapes();
        return true;
    }

    return false;
}
