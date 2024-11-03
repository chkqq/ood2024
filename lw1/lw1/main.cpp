#include "Application.h"

int main()
{
    std::shared_ptr<Application> app = Application::getInstance();
    app->run();

    return 0;
}
