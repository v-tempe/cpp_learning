#include <iostream>

using namespace std;


int main()
{
    setlocale(0, "");


    int n;
    int k;

    cout << "Введите кол-во ступенек:\n";
    cin >> n;
    cout << "Введите кол-во орехов:\n";
    cin >> k;

    int max_cast_amount = 0;

    int p;
    for (int p = 0; p <= n; p++) {  // перебираем значения для прочности в цикле
        // и выбираем максимальное кол-во бросков, которое понадобится обезьяне

        int dn = 0;
        int up = n+1;

        int cast_amount = 0;

        int medium;
        int res = 0;
        while (!res) {
            medium = (dn + up) / 2;
            //cout << "    " << dn << ' ' << medium << ' ' << up << endl;
            if (medium <= p) {
                dn = medium;
            }
            else {
                up = medium;
            }

            cast_amount ++;

            if (dn + 1 == up) {  // смежные ступени
                res = 1;
            }
            else if (cast_amount == k) {  // закончились орехи
                res = 2;
            }
        }
        if (res == 1) {
            //cout << "Потребовалось бросков: " << cast_amount << endl;
            if (cast_amount > max_cast_amount) max_cast_amount = cast_amount;
        }
        else if (res == 2) {
            //cout << "Обезьяне не хватает орехов, чтобы точно определить их прочность" << endl;
            max_cast_amount = -1;
        }
    }

    if (max_cast_amount == -1) {
        cout << "Обезьяне не хватает орехов, чтобы точно определить их прочность" << endl;
    }
    else {
        cout << "Потребуется бросков: " << max_cast_amount << endl;
    }


    return 0;
}
