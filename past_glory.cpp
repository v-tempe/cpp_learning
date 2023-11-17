#include <iostream>

using namespace std;

int main()
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 18; j++) {
            if ((i < 4) and (j < 6)) cout << "* ";
            else cout << "__";
        }
        cout << endl;

    }

    return 0;
}
