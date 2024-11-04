#include "Application.h"
#include "FileManager.h"
const std::string INPUT_FILE_NAME = "input.txt";
const std::string OUTPUT_FILE_NAME = "output.txt";
int main()
{
    std::vector<std::shared_ptr<MathDecorator>> shapes = LoadShapesFromFile(INPUT_FILE_NAME);
    SaveResultsToFile(shapes, OUTPUT_FILE_NAME);

    std::shared_ptr<Application> app = Application::getInstance();
    app->run();

    return 0;
}
