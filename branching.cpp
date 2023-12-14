#include <iostream>
#include <math.h>

using namespace std;

float a = 0;
float x = 0;

float mx = 0;


int main()
{
	cin >> a;
	cin >> x;

	if (x == 0){
        cout << "The 'x' value must not be 0";
        return 0;
	}

	mx = abs(x);

	if(mx < 1){
    	cout << a * log(mx);
	}
	else{
    	if(a >= mx*mx){
        	cout << sqrt(a - mx*mx);
    	}
    	else{
        	cout << "The 'a' value must be greater or equals than 2nd power of 'x' value";
    	}
	}
}
