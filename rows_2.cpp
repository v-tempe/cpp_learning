#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


// N 24
int n;
int base_from = 7;
int base_to = 3;

int number_length(int number) {
    int res = 0;
    //cout << "    " << "number: " << number << endl;
    while (number > 0) {
        res += 1;
        //cout << "        " << res << endl;
        number /= 10;
    }
    //cout << "number_length_res: " << res << endl;
    return res;
}

int to_decimal(int number) {
    int res = 0;
    //cout << "number: " << number << endl;
    int num_len = number_length(number);

    for (int i = 0; i < num_len; i++) {
        res += (number % 10) * pow(base_from, i);
        //cout << "    " << (number % 10) * pow(base_from, i) << endl;
        number /= 10;
        //cout << "    " << number << endl;
        //cout << "    " << res << endl;
    }
    //cout << "  " << number_length(number) << endl;
    return res;
}

int from_decimal(int number) {
    int res = 0;
    int i = 0;
    while (number > 0) {
        res += (number % base_to) * pow(10, i);
        //cout << number % base_to << endl;
        number /= base_to;

        i++;
    }
    return res;
}


int main()
{
    cin >> n;
    vector<int> input_array (n, 0);
    vector<int> output_array (n, 0);



    for (int i = 0; i < n; i++) {
        cin >> input_array[i];
    }

    int cur_digit;
    int decimal_number;
    for (int i = 0; i < n; i++) {
        cur_digit = input_array[i];
        //cout << to_decimal(cur_digit) << endl;
        decimal_number = to_decimal(cur_digit);
        //cout << decimal_number << endl;
        cout << from_decimal(decimal_number) << endl;

    }

    return 0;
}

