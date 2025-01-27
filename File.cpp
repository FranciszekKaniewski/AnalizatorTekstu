#include "Headers/File.h"
#include "Headers/App.h"
#include "map"
#include <cctype>
using namespace std;

void File::load() {
    if(textFile.is_open()) {
        cout << "File is already loaded!\n";
        return;
    }
    cout<<"Provide a file path: ";
    cin>>filePath;

    textFile.open(filePath, ios::in);

    textFile.good() ? cout<<"File loaded correctly!\n" : cout<<"File load error X(, try again!\n";
}

void File::show() {
    string line = "";
    if(!textFile.is_open()) {
        cout << "File isn't loaded yet!\n";
        return;
    }

    textFile.clear();
    textFile.seekg(0, ios::beg);

    cout << "Loaded File: " << filePath << endl;
    cout << "\n ==================== " << filePath << " ==================== \n";
    while(!textFile.eof()){
        getline(textFile, line);
        cout << line << endl;
    }
}

void File::remove() {
    if(!textFile.is_open()) {
        if(App::isRunning) cout << "File isn't loaded yet!\n";
        return;
    }

    filePath = "";
    textFile.close();
    cout << "File removed!\n";
}

map<string, int> File::getMapOfWords() {
    map<string, int> mapOfWords;
    string word;
    string lowWord;

    textFile.clear();
    textFile.seekg(0, ios::beg);

    while (this->textFile >> word) {
        lowWord = "";
        for(char ch : word){
            if(!isalpha(ch)) continue;
            lowWord += tolower(ch);
        }
        mapOfWords[lowWord] ++;
    }

    return mapOfWords;
}

map<char, int> File::getMapOfCharacters() {
    map<char, int> mapOfChars;
    char c;
    char lowChar;

    textFile.clear();
    textFile.seekg(0, ios::beg);

    while (this->textFile >> c) {
        lowChar = tolower(c);
        mapOfChars[lowChar] ++;
    }

    return mapOfChars;
}

void File::printMapOfWords() {

    map<string, int> mapOfWords = this->getMapOfWords();

    multimap<int, string> sortedMap;
    for (const auto& [key, value] : mapOfWords) {
        sortedMap.insert({value, key});
    }


    auto firstElement = sortedMap.begin();
    auto lastElement = sortedMap.rbegin();

    int least = 0;
    int max = 99999;

    if (firstElement != sortedMap.end()) {
        least = firstElement->first;
        max = lastElement->first;
    } else {
        std::cout << "Map is empty!" << std::endl;
    }

    cout << "Most common words: \n";
    for (const auto& entry : sortedMap) {
        if(entry.first > least) break;
        cout << entry.second << ": " << entry.first << endl;
    }

    cout << "Least common words: \n";
    for (auto e = sortedMap.rbegin(); e != sortedMap.rend(); ++e) {
        if(e->first < max) break;
        cout << e->second << ": " << e->first << endl;
    }
}

void File::printMapOfCharacters() {
    map<char, int> mapOfChars = this->getMapOfCharacters();

    for (const auto& entry : mapOfChars) {
        cout << entry.first << ": " << entry.second << endl;
    }
}