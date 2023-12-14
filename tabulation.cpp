#include <iostream>
#include <math.h>

using namespace std;

int n;
float y;


int main()
{
	float x;
	for (x = -4; x <= 4; x += 0.5)
	{
    	if (x - 1 != 0) {
            y = (x*x - 2*x + 2)/(x - 1);
            cout << x << '\t' << y << endl;}
    	else {
            cout << "Function is undefined" << endl;
    	}

	}
}
