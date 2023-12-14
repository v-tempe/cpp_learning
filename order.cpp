#include <iostream>
#include <math.h>

using namespace std;

double d;

int main()
{
    int i;

    cout << "Input the number: ";
	cin >> d;
	cout << endl;

	if (d <= 0) i = 1;
	else i = ceil(d);

	for (int j = i; j < i+10; j++) cout << j << endl;
}
