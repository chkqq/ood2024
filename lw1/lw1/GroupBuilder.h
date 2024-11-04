#include "ShapeBuilder.h"
#include "Group.h"
#include <sstream>

class GroupBuilder : public ShapeBuilder {
private:
    std::shared_ptr<Group> group;
    std::vector<std::unique_ptr<ShapeBuilder>>& builders;

public:
    GroupBuilder(std::vector<std::unique_ptr<ShapeBuilder>>& buildersList)
        : builders(buildersList) {}

    void buildShape(const std::string& data) override {
        std::istringstream iss(data);
        std::string type;
        size_t shapeCount;

        iss >> type >> shapeCount;

        if (type == "Group") {
            group = std::make_shared<Group>();
            std::string shapeData;
            for (size_t i = 0; i < shapeCount; ++i) {
                std::getline(iss, shapeData, ';');
                for (auto& builder : builders) {
                    builder->buildShape(shapeData);
                    auto shape = builder->getResult();
                    if (shape) {
                        group->AddShape(shape);
                        break;
                    }
                }
            }
        }
    }

    std::shared_ptr<Shape> getResult() override {
        return group;
    }
};
