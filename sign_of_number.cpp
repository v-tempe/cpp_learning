#include <iostream>

using namespace std;


int sign(double x) {
    if (x == 0) {
        return 0;
    }
    else if (x > 0) {
        return 1;
    }
    else {
        return -1;
    }
}


double x = 0;

int main()
{
    cin >> x;

    cout << sign(x);
}
