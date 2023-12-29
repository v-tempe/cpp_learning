#include <iostream>

using namespace std;


int main()
{
    setlocale(0, "");


    int n;
    int k;

    cout << "������� ���-�� ��������:\n";
    cin >> n;
    cout << "������� ���-�� ������:\n";
    cin >> k;

    int max_cast_amount = 0;

    int p;
    for (int p = 0; p <= n; p++) {  // ���������� �������� ��� ��������� � �����
        // � �������� ������������ ���-�� �������, ������� ����������� ��������

        int dn = 0;
        int up = n+1;

        int cast_amount = 0;

        int medium;
        int res = 0;
        while (!res) {
            medium = (dn + up) / 2;
            //cout << "    " << dn << ' ' << medium << ' ' << up << endl;
            if (medium <= p) {
                dn = medium;
            }
            else {
                up = medium;
            }

            cast_amount ++;

            if (dn + 1 == up) {  // ������� �������
                res = 1;
            }
            else if (cast_amount == k) {  // ����������� �����
                res = 2;
            }
        }
        if (res == 1) {
            //cout << "������������� �������: " << cast_amount << endl;
            if (cast_amount > max_cast_amount) max_cast_amount = cast_amount;
        }
        else if (res == 2) {
            //cout << "�������� �� ������� ������, ����� ����� ���������� �� ���������" << endl;
            max_cast_amount = -1;
        }
    }

    if (max_cast_amount == -1) {
        cout << "�������� �� ������� ������, ����� ����� ���������� �� ���������" << endl;
    }
    else {
        cout << "����������� �������: " << max_cast_amount << endl;
    }


    return 0;
}
