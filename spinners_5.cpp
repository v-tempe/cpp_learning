#include <iostream>
#include <vector>
#include <map>

using namespace std;


int N = 0;
int K = 0;


int find_max(map<int, int> ranges) {
    int max_first = 0;
    int max_second = 0;
    for (pair cur_range : ranges) {
        if ((cur_range.second - cur_range.first) > (max_second - max_first)) {
            max_first = cur_range.first;
            max_second = cur_range.second;
        }
    }
    //cout << max_first << ' ' << ranges[max_first] << endl;
    return max_first;
}

// левое
int main()
{
    cin >> N;
    N += 2;
    cin >> K;
    
    vector<bool> row (N, false);
    row[0] = true;
    row[N-1] = true;
    
    map<int, int> ranges { {0, N-1} };
    
    int cur_chair;
    int i = 0;
    int j = N-1;
    for (int _ = 0; _ < K; _++) {
        i = find_max(ranges);
        j = ranges[i];
        
        cur_chair = (i + j) / 2;
        
        row[cur_chair] = true;
        ranges[i] = cur_chair;
        ranges[cur_chair] = j;
    }
    
    
    for (auto elem : row) cout << elem << ' ';
    cout << endl;
    cout << cur_chair - i - 1 << ' ' << j - cur_chair - 1 << endl;

    return 0;
}
