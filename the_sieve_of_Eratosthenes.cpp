#include <iostream>
#include <vector>

using namespace std;


int n;
int amount = 0;

int main()
{
    cin >> n;

    vector<bool> a (n, true);
    vector<int> b;


    for (int j = 2; j < n; j++) {
        if (a[j] == true) {
            amount ++;
            b.push_back(j);
            for (int i = j + j; i < n; i += j) {
                a[i] = false;
            }
        }
    }



    cout << amount << endl;
    for (int elem : b) cout << elem << ' ';

    return 0;
}
