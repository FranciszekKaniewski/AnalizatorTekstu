#include "./Headers/Levenshtein.h"
#include <limits>

int minimum(int x1, int x2, int x3){
    if (x1 >= x2)
        if (x2 >= x3)
            return x3;
        else
            return x2;
    else
    if (x3 >= x1)
        return x1;

    return x3;
}

int Levenshtein::getLevenshteinValue(std::string a, std::string b) {

    int d[100][100];
    int m, n, i, j, cost;

    m = a.size();
    n = b.size();

    for (i=0; i<=m; i++)
        d[i][0] = i;
    for (j=0; j<=n; j++)
        d[0][j] = j;

    for (i=1; i<=m; i++){
        for (j=1; j<=n; j++){
            if (a[i-1] == b[j-1])
                cost = 0;
            else
                cost = 1;

            d[i][j] = minimum(d[i-1][j] + 1,d[i][j-1] + 1,d[i-1][j-1] + cost);
        }
    }

    return d[m][n];
}

void Levenshtein::fn(map<std::string, int> map) {
    vector<std::string> v;
    std::string sen, lowWord;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin,sen);

    for (int i=0;i<sen.size();i++) {

        char ch = sen[i];

        if(sen[i] == ' '){
            v.push_back(lowWord);
            lowWord = "";
            continue;
        }
        if(!isalpha(sen[i])) continue;
        lowWord += tolower(ch);
    }
    if(lowWord.size()>0)v.push_back(lowWord);

    for(int i=0;i<v.size();i++){
        std::string correctWord = "";
        bool show = true;
        int min = 99999;
        for (const auto& entry : map) {
            if(entry.first == v[i]) {
                show = false;
                break;
            }

            if(Levenshtein::getLevenshteinValue(v[i],entry.first)<min){
                min = Levenshtein::getLevenshteinValue(v[i],entry.first);
                correctWord = entry.first;
            }
        }
        if(show) cout << "Word: " << v[i] << " do not exist in your file, did you mean: " << correctWord << " ?" << '\n';
    }
}