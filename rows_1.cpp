#include <iostream>
#include <math.h>

using namespace std;


// N 1
int main()
{
    int n = 0;
    double y = 0;
    cin >> n;


    double cur_sin = 0;
    double cur_sum = 0;
    double total_sum = 0;
    for (int i = 1; i <= n; i++) {
        cur_sin += sin(i);
        cur_sum += 1 / (cur_sin);
        total_sum += cur_sum;
    }


    cout << total_sum;

    return 0;
}
