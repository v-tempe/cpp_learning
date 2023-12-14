#include <iostream>
#include <fstream>
#include <map>

using namespace std;


char s[30] = "eiejeufhfvucvndhfoeioejekjeej";
map<char, int> d;

int main()
{
    for (int k=97; k<=122; k++){
        d[k] = 0;
    }

    for (int i=0; i<30; i++){
        char k = s[i];
        if (d.count(k) >= 1){
            d[k] += 1;
        }
        else{
            d[k] = 0;
        }
    }

    for (const auto& [k, v]: d){
        for (int j=0; j<v; j++){
            cout << k;
        }
    }
}
