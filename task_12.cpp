#include <iostream>//подключение библиотеки длЯ ввода и вывода

#include <vector>//подключение библиотеки длЯ работы с векторами

#include <csignal>//подключение библиотеки длЯ обработки сигналов

using namespace std;//поделючение пространства имен std



volatile int interrupted;//флаг наличиЯ сигнала ctrl+c


void signalHandler(int signal) {//функциЯ длЯ обработки сигнала ctrl+c

    interrupted = 1;
}



int main()
{
    setlocale(LC_ALL, "RUS");  //корректное отображение кириллицы

    string alf = "qwertyuiopasdfghjklzxcvbnm";
    string vowels = "eyuioa";
    string size = "2345";

    string input = "";
    interrupted = 0;


    cout << "Пожалуйста, введите целое число в диапазоне [2; 5]";

    signal(SIGINT, signalHandler);//установка обработчика сигнала ctrl+c

    cin >> input;

    while (interrupted == 1 || (cin.fail()) || input.length() != 1 ||(size.find(input[0]) == string::npos)) {
        if (cin.eof()) { cin.clear(); }//обработка ctrl+z
        else {//обработка остальных причин неверного ввода
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Ћшибка! Џопробуйте еще раз: ";
        interrupted = 0;
        signal(SIGINT, signalHandler);//установка обработчика сигнала ctrl+c
        cin >> input;
    }





}
