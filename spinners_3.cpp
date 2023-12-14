#include <iostream>

using namespace std;


int M = 0;
int N = 0;


int sum_to_n(int n, bool inclusive=true) {  // сумма натуральных чисел от 1 до n
    int summ = 0;

    for (int i = 0; i < n; i++) {
        summ += i;
    }
    if (inclusive) {
        summ += n;
    }

    return summ;
}


int main()
{
    cin >> M;
    cin >> N;

    cout << sum_to_n(M) * sum_to_n(N);

    return 0;
}
