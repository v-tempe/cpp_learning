#include <iostream>
#include <vector>

using namespace std;


int N = 3;

vector<vector<int>> a (1, vector<int> (1, 1));

int main()
{
    cin >> N;

    vector<vector<int>> b;

    for (int i = 2; i <= N; i++) {
        b = a;
        a.clear();
        for (vector<int> temp_vector : b) {
            for (int j = 0; j < i; j++) {
                vector<int> temp_vector1 = temp_vector;
                auto iter = temp_vector1.cbegin();
                temp_vector1.emplace(iter + j, i);
                a.push_back(temp_vector1);
            }
        }
    }


    int amount = 0;
    for (vector<int> row : a) {
        bool fl = false;

        int lenn = size(row);
        for (int i = 0; i < lenn; i++) {
            if (i+1 == row[i]) {
                fl = true;
            }
        }
        if (fl) {
            amount ++;
        }
    }


    /*for (auto row : a) {
        for (auto elem : row) {
            cout << elem << ' ';
        }
        cout << endl;
    }*/

    cout << amount;

    return 0;
}
