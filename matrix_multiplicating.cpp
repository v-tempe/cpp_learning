#include <iostream>

using namespace std;


int amount_of_cellers = 3;
int amount_of_goods = 4;

float matrix_a[3][4] = {
    {5, 2, 0, 10},
    {3, 5, 2, 5},
    {20, 0, 0, 0}
};

float matrix_b[4][2] = {
    {1.20, 0.50},
    {2.80, 0.40},
    {5.00, 1.00},
    {2.00, 1.50}
};

float matrix_c[3][2] = {
    {0, 0},
    {0, 0},
    {0, 0}
};

float elem = 0;

void print_matrix(float matrix[3][2]) {
    for (int i=0; i<3; i++) {
        for (int j=0; j<2; j++) {
            cout << matrix[i][j];
            if (j<1) cout << '\t';
        }
        cout << endl;
    }
}

int main()
{
    // перемножаем матрицы
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            elem = 0;
            for (int k = 0; k < 4; k++) {
                elem += matrix_a[i][k] * matrix_b[j][k];
            }
            matrix_c[i][j] = elem;
        }
    }

    print_matrix(matrix_c);



    return 0;
}
