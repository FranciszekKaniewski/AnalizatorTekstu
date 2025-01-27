#include "string"
#include "map"
#include "iostream"
#include "vector"
using namespace std;

class Levenshtein{
public:
    static int getLevenshteinValue(string a, string b);
    static std::string getCorrectWord(string a, map<string,int> map);
    static void fn(map<string,int> map);
};