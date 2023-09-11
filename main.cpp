#include <iostream>
#include "Application.h"
#include "Hlpr.h"

int main()
{
    Hlpr::ShowConsoleCursor(false);
    Application app;
    app.Run();
}
