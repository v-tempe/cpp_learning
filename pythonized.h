#include <iostream>
#include <string>

using namespace std;


double input(string prompt = "")
{
	double value;

	cout << prompt;
	cin >> value;
	return value;
}


void print(auto value)
{
	cout << value;
	cout << endl;
}


void debug()
{

}


void input_1(string prompt = "")
{

}


string reversed(string original) {
    string result = "";
    for (int i = original.length()-1; i >= 0; i--) result += original[i];
    return result;
}
