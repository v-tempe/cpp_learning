#include <iostream>

using namespace std;


int nod(int a, int b) {
    if (a < b) {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    while ((a != 0) (b != 0)) {

    }
}


int gcd(int a, int b) {
    while ((a != 0) && (b != 0)) {
        if (a > b) a = a - b;
        else b = b - a;
        //cout << a << ' ' << b << endl;
    }
    if (a != 0) return a;
    else return b;
}


int a = 0;
int b = 0;

int main()
{
    cin >> a;
    cin >> b;
    cout << gcd(a, b);

    return 0;
}
