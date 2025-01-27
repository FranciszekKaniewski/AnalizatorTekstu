#include "Headers/App.h"
#include "iostream"
#include "ctype.h"
#include "Headers/Interface.h"
#include "Headers/File.h"
#include "./Headers/Levenshtein.h"
#include "string"
#include "map"
#include "vector"
using namespace std;

File* file = nullptr;
Interface* interface = nullptr;

bool App::isRunning = false;
void App::init() {
    App::isRunning = true;

    file = new File;
    interface = new Interface;

    interface->startMenu();
}

void App::handleEvents() {

    char c = '0';
    cout<<"\nProvide a file command: ";
    cin >> c;

    switch(tolower(c)){
        case 'q':
            isRunning = false;
            break;
        case 'h':
            interface->options();
            break;
        case 'l':
            file->load();
            break;
        case 's':
            file->show();
            break;
        case 'r':
            file->remove();
            break;
        case 'm':
            file->printMapOfWords();
            break;
        case 'n':
            file->printMapOfCharacters();
            break;
        case 'o':
            Levenshtein::fn(file->getMapOfWords());
//            Levenshtein::getCorrectWord("Kotek",file->getMapOfWords());
            break;
        default:
            cout<<"No action for your character: "<< c << " :( \n";
            break;
    }
}

void App::clean() {
    file->remove();
}