#include <iostream>
#include <math.h>
#include <string>
#include <set>

using namespace std;


float rectangle(float a, float b) {
    return a * b;
}


float triangle(float a, float h) {
    return 0.5 * a * h;
}


float circle(float r) {
    return r * r * M_PI;
}


set<string> possible_types_of_figure {"rectangle", "triangle", "circle"};

string type_of_figure = "";

float res = 0;

int main()
{
    cin >> type_of_figure;

    if (possible_types_of_figure.contains(type_of_figure)) {
        if (type_of_figure == "rectangle") {
            float a = 0;
            float b = 0;
            cin >> a;
            cin >> b;
            res = rectangle(a, b);
        }
        else if (type_of_figure == "triangle") {
            float a = 0;
            float h = 0;
            cin >> a;
            cin >> h;
            res = triangle(a, h);
        }
        else {
            float r = 0;
            cin >> r;
            res = circle(r);
        }
    }

    cout << res;

    return 0;
}

