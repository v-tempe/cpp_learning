#include <iostream>
#include <fstream>
#include <string>

using namespace std;


// N 6
int main()
{
    string min_word;

    ifstream fin;
    fin.open("Documents/file_1.txt");
    string word;
    fin >> min_word;
    for (int i = 1; i<100; i++) {
        fin >> word;
        if (word.length() < min_word.length()) min_word = word;
    }

    cout << min_word;

    return 0;
}
