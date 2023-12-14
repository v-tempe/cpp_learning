#include <iostream>
#include <math.h>
#include "pythonized.h"

using namespace std;


float S;
float p;
float n;
double m;

int main()
{
    S = input("input S: ");
    p = input("input p: ");
    n = input("input n: ");

    if ((S == 0) || (p == 0) || (n == 0)) {
        cout << "Incorrect value(s). All values must be positive.";
        return 0;
    }

    float r = p / 100;
    float k = pow(1 + r, n);

    double numerator = S * r * k;
    double denomenator = 12 * (k - 1);

    m = numerator / denomenator;

    print(m);

    return 0;
}
