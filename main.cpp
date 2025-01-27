#include "Headers/App.h"

App* app = nullptr;
int main(){

    app = new App;
    app->init();

    while(app->running())
        app->handleEvents();

    app->clean();

    delete app;
    return 0;
}