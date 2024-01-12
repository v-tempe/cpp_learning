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

    string alf = "qwertyuiopasdfghjklzxcvbnm";

    string vowels = "eyuioa";

    string size = "2345";

    string input = "";

    interrupted = 0;

    setlocale(0, "");//корректное отображение кириллицы



    //ввод и проверка размера матрицы

    cout << "‚ведите размер квадратной матрицы от 2 до 5: ";

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

    int m = input[0] - '0';



    //ввод и проверка буквы

    cout << "‚ведите букву: ";

    signal(SIGINT, signalHandler);//установка обработчика сигнала ctrl+c

    cin >> input;

    while (interrupted == 1 || (cin.fail()) || input.length() != 1 || alf.find(input[0]) == string::npos) {

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

    char c = input[0];



    vector<vector<string> > matrix(m);//матрица размера m

    vector<string> words;//массив длЯ слов с искомой буквой

    vector<int> countOfVowels;//массив длЯ количества гласных в каждом слове из words



    //выбор способ заполнениЯ матрицы

    cout << "‚ведите 1 длЯ ручного ввода или 2 длЯ автоматического: ";

    signal(SIGINT, signalHandler);//установка обработчика сигнала ctrl+c

    cin >> input;

    while (interrupted == 1 || (cin.fail()) || input.length()!= 1||((input[0]!='1') && (input[0]!='2'))) {

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

    int r = input[0]-'0';



    //заполнение матрицы

    srand(time(0));

    for (int i = 0; i < m; i++) {

        for (int j = 0; j < m; j++) {

            string str = "";

            if (r == 2) {//заполнение матрицы случайными комбинациЯми

                    str = string(1, alf[rand() % alf.length()]) +

                    string(1, alf[rand() % alf.length()]) +

                    string(1, alf[rand() % alf.length()]) +

                    string(1, alf[rand() % alf.length()]);//генерациЯ строки из 4 случайных букв

                matrix[i].push_back(str);//заполнение матрицы (matrix) случайными комбинациЯми 4 букв

            }

            else {//ручной ввод

                cout << "‚ведите слово из 4 букв: ";

                cin >> str;

                while (interrupted == 1 || (cin.fail()) || str.length() != 4 ||

                    alf.find(str[0]) == string::npos || alf.find(str[1]) == string::npos ||

                    alf.find(str[2]) == string::npos || alf.find(str[3]) == string::npos) {

                    if (cin.eof()) { cin.clear(); }//обработка ctrl+z

                    else {//обработка остальных причин неверного ввода

                        cin.clear();

                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    }

                    cout << "Ћшибка! Џопробуйте еще раз: ";

                    interrupted = 0;

                    signal(SIGINT, signalHandler);//установка обработчика сигнала ctrl+c

                    cin >> str;

                }

            }

            //заполнение массива (words) слов, содержащих введенную букву

            if (str.find(c) != string::npos) {

                words.push_back(str);

                //подсчет количества гласных в каждом слове из массива words

                int k = 0;

                for (int g = 0; g < 4; g++) {

                    if (vowels.find(str[g]) != string::npos) {

                        k++;

                    }

                }

                //заполнение массива (countOfVowels), содержащего количество гласных в каждом слове из массива words

                countOfVowels.push_back(k);

            }

        }

    }



    //сортировка массива countOfVowels (и параллельно words) методом "пузырька" по возрастанию количества гласных

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



    //вывод результата в консоль

    if (words.size() == 0) {

        cout << "‘лов с этим символом в матрице нет";

    }

    else {

        cout << "ђезультат: ";

        for (int i = 0; i < words.size(); i++) {

            cout << words[i] << " ";

        }

    }

}



