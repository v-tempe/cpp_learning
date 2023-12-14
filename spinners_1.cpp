#include <iostream>

using namespace std;


int A = 0;
int B = 0;
int C = 0;

int main()
{
    cin >> A;
    cin >> B;
    cin >> C;

    int n = 0;
    while (A + n * B <= C) {

        n++;
    }
    n--;

    cout << n;

    return 0;
}
