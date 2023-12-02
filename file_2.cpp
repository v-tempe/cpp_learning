#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;


map<char, int> count_of_digits;

// N 19
int main()
{
    string min_word;

    for (int i = 65; i <= 90; i++) count_of_digits[i] = 0;

    ifstream fin;
    fin.open("Documents/file_1.txt");
    string word;
    fin >> min_word;
    for (int i = 1; i<100; i++) {
        fin >> word;
        for (int i = 0; i < word.length(); i++) {
            if (count_of_digits.count(i) || count_of_digits.count(i+32)) {
                count_of_digits[i] += 1;
            }
        }
    }

    char min_char = 65;
    int count_of_min_char = count_of_digits[65];
    for (const auto& [key, value] : count_of_digits) {
        //key = item.first;
        //value = item.second;
        if (value < count_of_min_char) {
            min_char = key;
            count_of_min_char = value;
        }
    }

    cout << min_char;

    return 0;
}
