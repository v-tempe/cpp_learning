#include <iostream>

using namespace std;


// используется минимальное кол-во оснований для спиннеров
int M = 0;
int amount4 = 0;
int amount3 = 0;

int main()
{
    cin >> M;

    if ((M == 1) || (M == 2) || (M == 5)) {
        amount3 = 0;
        amount4 = 0;
    }
    else {
        while (M % 4) {
            M -= 3;
            amount3 += 1;
        }
        amount4 = M / 4;
    }

    cout << amount3 << endl;
    cout << amount4 << endl;

    return 0;
}
