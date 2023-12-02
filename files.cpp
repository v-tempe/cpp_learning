#include <iostream>
#include <fstream>
#include <vector>

using namespace std;




// N 14
int main()
{
    ofstream fout;
    fout.open("like_task_27_from_USE.txt");
    fout << "43 0 854 6 6 6 7 8 6 5 7 87 8 4";

    fout.close();


    ifstream fin;
    fin.open("like_task_27_from_USE.txt");
    vector<int> task_27 (10, 0);
    for (int i = 0; i < 10; i++) fin >> task_27[i];


    int i_max = 0;  // хранит начало максмимального (на данный момент) отрезка массива (индекс)
    int max_len = 0; // хранит длину максмимального (на данный момент) отрезка массива
    // имеЯ индекс начала и длину отрезка массива, можно однозначно определить его его

    for (int i = 1; i < task_27.length() - 1; i++) {

        if (task_27[i-1] == task_27[i+1]) {  // случай с отрезком нечЮтной длины
            // предыдущее и следующее числа равны. Ќачинаем "круги на воде"
            int j = 1;
            while ((i+j < task_27.length()) && (i-j >= 0) && (task_27[i-j] == task_27[i+j]) {
                j++;
                if (j * 2 + 1 > max_len) {
                    i_max = i-j;
                    max_len = j * 2 + 1;
                }
            }
        }

        if (task_27[i-1] == task_27[i]) {  // случай с отрезком чЮтной длины
            int j = 1;
            while ((i+j-1 < task_27.length()) && (i-j >= 0) && (task_27[i-j] == task_27[i+j]) {
                j++;
        }
    }

    fin.close();

    return 0;
}
