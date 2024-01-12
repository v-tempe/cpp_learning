#include <iostream>//����������� ���������� ��� ����� � ������

#include <vector>//����������� ���������� ��� ������ � ���������

#include <csignal>//����������� ���������� ��� ��������� ��������

using namespace std;//����������� ������������ ���� std



volatile int interrupted;//���� ������� ������� ctrl+c



void signalHandler(int signal) {//������� ��� ��������� ������� ctrl+c

    interrupted = 1;

}



int main()

{

    string alf = "qwertyuiopasdfghjklzxcvbnm";

    string vowels = "eyuioa";

    string size = "2345";

    string input = "";

    interrupted = 0;

    setlocale(0, "");//���������� ����������� ���������



    //���� � �������� ������� �������

    cout << "������� ������ ���������� ������� �� 2 �� 5: ";

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

    int m = input[0] - '0';



    //���� � �������� �����

    cout << "������� �����: ";

    signal(SIGINT, signalHandler);//��������� ����������� ������� ctrl+c

    cin >> input;

    while (interrupted == 1 || (cin.fail()) || input.length() != 1 || alf.find(input[0]) == string::npos) {

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

    char c = input[0];



    vector<vector<string> > matrix(m);//������� ������� m

    vector<string> words;//������ ��� ���� � ������� ������

    vector<int> countOfVowels;//������ ��� ���������� ������� � ������ ����� �� words



    //����� ������ ���������� �������

    cout << "������� 1 ��� ������� ����� ��� 2 ��� ���������������: ";

    signal(SIGINT, signalHandler);//��������� ����������� ������� ctrl+c

    cin >> input;

    while (interrupted == 1 || (cin.fail()) || input.length()!= 1||((input[0]!='1') && (input[0]!='2'))) {

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

    int r = input[0]-'0';



    //���������� �������

    srand(time(0));

    for (int i = 0; i < m; i++) {

        for (int j = 0; j < m; j++) {

            string str = "";

            if (r == 2) {//���������� ������� ���������� ������������

                    str = string(1, alf[rand() % alf.length()]) +

                    string(1, alf[rand() % alf.length()]) +

                    string(1, alf[rand() % alf.length()]) +

                    string(1, alf[rand() % alf.length()]);//��������� ������ �� 4 ��������� ����

                matrix[i].push_back(str);//���������� ������� (matrix) ���������� ������������ 4 ����

            }

            else {//������ ����

                cout << "������� ����� �� 4 ����: ";

                cin >> str;

                while (interrupted == 1 || (cin.fail()) || str.length() != 4 ||

                    alf.find(str[0]) == string::npos || alf.find(str[1]) == string::npos ||

                    alf.find(str[2]) == string::npos || alf.find(str[3]) == string::npos) {

                    if (cin.eof()) { cin.clear(); }//��������� ctrl+z

                    else {//��������� ��������� ������ ��������� �����

                        cin.clear();

                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    }

                    cout << "������! ���������� ��� ���: ";

                    interrupted = 0;

                    signal(SIGINT, signalHandler);//��������� ����������� ������� ctrl+c

                    cin >> str;

                }

            }

            //���������� ������� (words) ����, ���������� ��������� �����

            if (str.find(c) != string::npos) {

                words.push_back(str);

                //������� ���������� ������� � ������ ����� �� ������� words

                int k = 0;

                for (int g = 0; g < 4; g++) {

                    if (vowels.find(str[g]) != string::npos) {

                        k++;

                    }

                }

                //���������� ������� (countOfVowels), ����������� ���������� ������� � ������ ����� �� ������� words

                countOfVowels.push_back(k);

            }

        }

    }



    //���������� ������� countOfVowels (� ����������� words) ������� "��������" �� ����������� ���������� �������

    for (int i = 0; i < words.size(); i++) {

        for (int j = 0; j < words.size() - i - 1; j++) {

            if (countOfVowels[j] > countOfVowels[j + 1]) {

                int bufi = countOfVowels[j];

                string bufs = words[j];

                countOfVowels[j] = countOfVowels[j + 1];

                words[j] = words[j + 1];

                countOfVowels[j + 1] = bufi;

                words[j + 1] = bufs;

            }

        }

    }



    //����� ���������� � �������

    if (words.size() == 0) {

        cout << "���� � ���� �������� � ������� ���";

    }

    else {

        cout << "���������: ";

        for (int i = 0; i < words.size(); i++) {

            cout << words[i] << " ";

        }

    }

}



