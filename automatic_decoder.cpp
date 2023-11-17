#include <iostream>
#include <string.h>
#include <stack>
#include <map>


using namespace std;

char digits[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
stack<int> romanian_digits_stack;


string input_string;

int res = 0;


int mantissa(int num) {
    while (num >= 10) {
        num /= 10;
    }
    return num;
}


int main()
{
    char cur;
    int tcur;
    char next;
    int tnext;

    cin >> input_string;

    map<char, int> translation
    {    {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}    };

    map<char, int> count
    {    {'I', 0}, {'V', 0}, {'X', 0}, {'L', 0}, {'C', 0}, {'D', 0}, {'M', 0}    };

    romanian_digits_stack.push(0);
    for (auto d: digits) romanian_digits_stack.push(translation[d]);


    int i = 0;
    for (i = 0; i < input_string.length(); i++) {

        cur = input_string[i];
        count[cur]++;
        if (count[cur] > 3) {
            //cout << "case_3 " << i << " Fuck you!" << endl;
            cout << "This romanian number doesn't exist" << endl;
            return 1;
        }
        tcur = translation[cur];
        //cout << "i=" << i << " tcur=" << tcur << " stack_top=" << romanian_digits_stack.top() << endl;
        if (tcur > romanian_digits_stack.top()) {
            //cout << "case_4 " << i << " Fuck you! " << romanian_digits_stack.top() << endl;
            cout << "This romanian number doesn't exist" << endl;
            return 1;
        }
        else {
            //cout << "i=" << i << ' ';
            while (tcur < romanian_digits_stack.top()){
            //cout << romanian_digits_stack.top() << ' ';
            romanian_digits_stack.pop();
            }
            //cout << "stack_top: " << romanian_digits_stack.top() << endl;
        }

        if (i == input_string.length() - 1) {
            res += tcur;
        }

        else {
            next = input_string[i+1];
            tnext = translation[next];
            if (mantissa(tcur) == 5) {  // кратное 5
                if (tcur > tnext) {
                    res += tcur;
                }
                else {
                    //cout << "case_1 " << i << " Fuck you!" << endl;
                    cout << "This romanian number doesn't exist" << endl;
                    return 1;
                }
            }

            else {  // не кратное 5
                if (tcur > tnext) {
                    res += tcur;
                }
                else if (tcur == tnext) {
                    res += tcur;
                }
                else if (tcur * 5 == tnext) {
                    if (translation[input_string[i-1]] == tnext) {
                        //cout << "case_5 " << i << " Fuck you!" << endl;
                        cout << "This romanian number doesn't exist" << endl;
                        return 1;
                    }

                    res += tnext;
                    res -= tcur;

                    romanian_digits_stack.pop();

                    i++;
                }
                else if (tcur * 10 == tnext) {
                    if (i > 0) {
                        if (translation[input_string[i-1]] < tnext) {
                            //cout << "case_6 " << i << " Fuck you!" << endl;
                            cout << "This romanian number doesn't exist" << endl;
                            return 1;
                        }
                    }

                    res += tnext;
                    res -= tcur;

                    romanian_digits_stack.pop();

                    i++;
                }
                else {
                    //cout << "case_2 " << i << " Fuck you!" << endl;
                    cout << "This romanian number doesn't exist" << endl;
                    return 1;
                }
            }
        }
    }
    cout << res;
}

