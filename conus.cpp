#include <iostream>
#include <math.h>

using namespace std;

float R = 0;
float r = 0;
float h = 0;
float l = 0;

float S = 0;
float V = 0;


int main()
{
    cin >> R >> r >> h;
    if ((r <= 0) || (R <= 0) || (h <= 0)){
        cout << "All input values must be positive";
        return 0;
    }

    if (r >= R)
    {
   	    float abequalsba = r;
   	    r = R;
   	    R = abequalsba;
    }
    l = sqrt((R-r) * (R-r) + h * h);
    cout << l << endl;

    S = M_PI * (R*R + l * (R+r) + r*r);
    V = M_PI * h * (R*R + R*r + r*r) / 3;

    cout << "S is ";
    cout << S;
    cout << "\n";
    cout << "V is ";
    cout << V;
}


