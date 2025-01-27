#include "fstream"
#include "iostream"
#include "vector"
#include "map"
#include "string"

class File{
public:
    std::string filePath;
    std::fstream textFile;

    ~File();
    void load();
    void show();
    void remove();

    std::map<std::string, int> getMapOfWords();
    std::map<char, int> getMapOfCharacters();

    void printMapOfWords();
    void printMapOfCharacters();
};