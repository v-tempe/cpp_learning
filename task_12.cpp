#include <iostream>//����������� ���������� �� ����� � ������

#include <vector>//����������� ���������� �� ������ � ���������

#include <csignal>//����������� ���������� �� ��������� ��������

using namespace std;//����������� ������������ ���� std



volatile int interrupted;//���� ������ ������� ctrl+c


void signalHandler(int signal) {//������ �� ��������� ������� ctrl+c

    interrupted = 1;
}



int main()
{
    setlocale(LC_ALL, "RUS");  //���������� ����������� ���������

    string alf = "qwertyuiopasdfghjklzxcvbnm";
    string vowels = "eyuioa";
    string size = "2345";

    string input = "";
    interrupted = 0;


    cout << "����������, ������� ����� ����� � ��������� [2; 5]";

    signal(SIGINT, signalHandler);//��������� ����������� ������� ctrl+c

    cin >> input;

    while (interrupted == 1 || (cin.fail()) || input.length() != 1 ||(size.find(input[0]) == string::npos)) {
        if (cin.eof()) { cin.clear(); }//��������� ctrl+z
        else {//��������� ��������� ������ ��������� �����
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "������! ���������� ��� ���: ";
        interrupted = 0;
        signal(SIGINT, signalHandler);//��������� ����������� ������� ctrl+c
        cin >> input;
    }





}
