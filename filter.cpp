#include <fstream>
#include <iostream>

using namespace std;


char s[100];

int main() {
    setlocale(LC_ALL, "");

    ofstream fout;
    fout.open("cppstudio.txt");
    fout << "Working with files 19 57 3853 7 57 47 7";
    fout.close();

    ifstream fin;
    fin.open("cppstudio.txt");
    fin.getline(s, 100);

    int i = 0;
    for (int i=0; i<100; i++){
        if (isdigit(s[i])){
            cout << s[i];
        }
    }

    fin.close();
    cout << endl;
}
