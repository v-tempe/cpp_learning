#include <iostream>
#include <math.h>

using namespace std;


int m;
int i;
int c;
int s;

int main()
{
    m = 37;
    i = 3;
    c = 64;
    s = 0;

    for (int j = 0; j < 10; j++) {
        s = (m * s + i) % c;
        cout << s << endl;
    }

    cout << endl;

    m = 25173;
    i = 13849;
    c = 65537;
    s = 0;

    for (int j = 0; j < 10; j++) {
        s = (m * s + i) % c;
        cout << s << endl;
    }

    return 0;
}
