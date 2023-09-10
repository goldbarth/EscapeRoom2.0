#include <iostream>
#include "Application.h"

int main()
{
    Application app{};
    app.Run();
    delete &app;
    return 0;
}
