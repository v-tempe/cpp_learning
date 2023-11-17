#include <iostream>
#include "pythonized.h"

using namespace std;


const int mh = 11;
const int mw = 51;

char surface[mh][mw];

void print_matrix(char matrix[mh][mw]) {
    for (int i=0; i<mh; i++) {
        for (int j=0; j<mw; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

int main()
{

    // инициализация массива (пробелами)
    for (int i=0; i<mh; i++) {
        for (int j=0; j<mw; j++) {
            surface[i][j] = ' ';
        }
    }

    // чертим оси
    // строки, столбцы
    for (int i=0; i<mh; i++) {
        surface[i][mw/2] = '|';
    }
    for (int i=0; i<mw; i++) {
        surface[mh/2][i] = '-';
    }
    // начало координат
    surface[mh/2][mw/2] = '+';


    // чертим синусоиду
    // правее оси у
    for (int i=(mw/2)+1; i<mw; i++) {
        int x = i - (mw/2) - 1;
        if (x % 8 < 4) {  // выше оси x
            switch (x % 4) {
                case 0:
                    surface[mh/2-1][i] = '/';
                    break;
                case 1:
                    surface[mh/2-2][i] = '_';
                    break;
                case 2:
                    surface[mh/2-2][i] = '_';
                    break;
                case 3:
                    surface[mh/2-1][i] = '\\';
                    break;
            }
        }
        else {  // ниже оси x
            switch (x % 4) {
                case 0:
                    surface[mh/2+1][i] = '\\';
                    break;
                case 1:
                    surface[mh/2+1][i] = '_';
                    break;
                case 2:
                    surface[mh/2+1][i] = '_';
                    break;
                case 3:
                    surface[mh/2+1][i] = '/';
                    break;
            }
        }
    }

    // левее оси у
    for (int i=(mw/2)-1; i>=0; i--) {
        int x = i - (mw/2) + 1;
        if (x % 8 <= -4) {  // выше оси x
            switch (x % 4) {
                case 0:
                    surface[mh/2-1][i] = '\\';
                    break;
                case -1:
                    surface[mh/2-2][i] = '_';
                    break;
                case -2:
                    surface[mh/2-2][i] = '_';
                    break;
                case -3:
                    surface[mh/2-1][i] = '/';
                    break;
            }
        }
        else {
            switch (x % 4) {
                case 0:
                    surface[mh/2+1][i] = '/';
                    break;
                case -1:
                    surface[mh/2+1][i] = '_';
                    break;
                case -2:
                    surface[mh/2+1][i] = '_';
                    break;
                case -3:
                    surface[mh/2+1][i] = '\\';
                    break;
            }
        }
    }


    print_matrix(surface);

    return 0;
}
