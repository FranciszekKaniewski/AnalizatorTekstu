#include "Headers/Interface.h"
#include "iostream"
using namespace std;

void Interface::startMenu() {
    cout<<"                   | (_)        | |             | |     | |      | |        \n"
          "   __ _ _ __   __ _| |_ ______ _| |_ ___  _ __  | |_ ___| | _____| |_ _   _ \n"
          "  / _` | '_ \\ / _` | | |_  / _` | __/ _ \\| '__| | __/ _ \\ |/ / __| __| | | |\n"
          " | (_| | | | | (_| | | |/ / (_| | || (_) | |    | ||  __/   <\\__ \\ |_| |_| |\n"
          "  \\__,_|_| |_|\\__,_|_|_/___\\__,_|\\__\\___/|_|     \\__\\___|_|\\_\\___/\\__|\\__,_|\n"
          "                                                           Franciszek Kaniewski umk inf.inz 2y"
        <<endl;
    cout<<"type h - for options list\n";
}

void Interface::options() {
    cout<<"h - commands list\n"
          "l - load text file\n"
          "r - remove loaded text file\n"
          "s - show loaded text\n"
          "m - show most and least common words\n"
          "n - count of every character in a text\n"
          "f - find a mistakes in a sentence\n"
          "q - exit program"
        << endl;
}

void Interface::bye() {
    cout<<"Bey, thanks for using analizator tekstu!"<<endl;
}