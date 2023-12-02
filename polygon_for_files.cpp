#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    ofstream fout;
    fout.open("Documents/file_1.txt");
    for (int i = 0; i<100; i++) fout << "Text" << endl;
    fout.close();

    return 0;
}
