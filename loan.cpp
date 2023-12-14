
#include <iostream>
#include <math.h>
#include "pythonized.h"

using namespace std;


float S;
float p;
float n;
double m0;

double m;


int order(int n) {
    int res = 0;
    while (n > 1) {
        n /= 10;
        res++;
    }
    return res;
}


int main()
{
    S = input("input S: ");
    m0 = input("input m: ");
    n = input("input n: ");

    double er = 0.001 * sqrt(S);

    if ((S == 0) || (m0 == 0) || (n == 0)) {
        cout << "Incorrect value(s). All values must be positive.";
        return 0;
    }


    for (float p=1; p<=100; p++) {
        float r = p / 100;
        float k = pow(1 + r, n);

        double numerator = S * r * k;
        double denomenator = 12 * (k - 1);

        m = numerator / denomenator;

        //cout << er << ' ';
        //print(m-m0);
        if (abs(m - m0) < er) {
            print(p);
            break;
        }
    }

    return 0;
}
