#include <fstream>
#include <iostream>

using namespace std;


float summ = 0;
float num = 10;

int main() {
    setlocale(LC_ALL, "");

    ofstream fout;
    fout.open("cppstudio.txt");
    fout << "0.5 -0.5 11.1 0 0 0 0 0 0 0";
    fout.close();


    ifstream fin;
    fin.open("cppstudio.txt");

    float n = 0;
    for (int i=0; i<num; i++){
        fin >> n;
        summ += n;
    }

    fin.close();

    cout << summ;
}
