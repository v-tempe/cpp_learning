#include <fstream>
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "");

    ofstream fout;
    fout.open("cppstudio.txt");
    fout << "Working with files 19 57 3853 7 57 47 7";
    fout.close();

    ifstream fin;
    fin.open("cppstudio.txt");
    char s[100];
    fin.getline(s, 100);

    fin.close();
    cout << s;
}
