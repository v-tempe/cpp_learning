#include <iostream>
#include <vector>

using namespace std;


int N = 0;
int amount = 0;

int main()
{
    cin >> N;
    vector<bool> coach (54, true);
    for (int _ = 0; _ < N; _++) {
        int i;
        cin >> i;
        coach[i-1] = false;
    }

    bool fl;
    for (int i = 0; i < 36; i += 4) {
        fl = false;
        for (int j = 0; j < 4; j++) {
            if (coach[i + j]) {
                fl = true;
                //cout << i + j << ' ' << coach[i+j] << endl;
            }
        }
        //cout << i << ' ';
        if (coach[54 - i / 2 - 1]) {
            fl = true;
            //cout << 54 - i / 2 - 1 << ' ' << coach[54 - i / 2 - 1] << endl;
        }
        if (coach[54 - i / 2 - 2]) {
            fl = true;
            //cout << 54 - i / 2 - 2 << ' ' << coach[54 - i / 2 - 2] << endl;
        }
        //cout << 54 - i / 2 << endl;

        if (!fl) {
            amount ++;
        }
    }


    cout << amount;

    return 0;
}
