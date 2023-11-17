#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include "pythonized.h"

using namespace std;


map<char, int> to_decimal;
map<int, char> from_decimal;

string orig_number;
string res_number;
int decimal_number;
int base_from;
int base_to;

double possible_base_from;
double possible_base_to;

int main()
{
    setlocale(0, "");

    // заполняем словари
	int i;
	char cur_digit;
	for (cur_digit = 48; cur_digit < 58; cur_digit++) {
    	i = cur_digit - 48;
    	//cout << '!' << cur_digit << "  " << i << '!' << endl;
    	to_decimal[cur_digit] = i;
    	from_decimal[i] = cur_digit;
	}

	cur_digit = 65;
	for (int i = 10; i < 36; i++) {
    	to_decimal[cur_digit] = i;
    	from_decimal[i] = cur_digit;
    	cur_digit++;
	}


	// вводим число
	cout << "Введите число: ";
	cin >> orig_number;

	for (auto digit : orig_number) {
	    if (!to_decimal.contains(digit)) {
	        print("Недопустимые знаки");
	        return 0;
	    }
	}

	cout << "Введите исходное основание: ";
	cin >> possible_base_from;
	/*
	if (possible_base_from % 1 != 0) {
	    print("Основание должно быть целым");
	    return 0;
	}
	*/
	if (! (2 <= base_from <= 35)) {
	    print("Неправильное основание");
	    return 0;
	}
	base_from = possible_base_from;

	cout << "Введите новое основание: ";
	cin >> possible_base_to;
	/*
	if (possible_base_to % 1 != 0) {
	    print("Основание должно быть целым");
	    return 0;
	}
	*/
	if (! (2 <= base_to <= 35)) {
	    print("Неправильное основание");
	    return 0;
	}
	base_to = possible_base_to;

	// проверяем, нет ли во ввведённом числе знаков, не существующих в заданной системе счисления
	for (auto digit : orig_number) {
	    if (to_decimal[digit] > base_from) {
	        print("Недопустимые числа в данной системе счисления");
	        print(to_decimal[digit]);
	        print(base_from);
	        return 0;
	    }
	}


	// переводим исходное число в десятичную сс
	decimal_number = 0;
	for (int i = 0; i < orig_number.length(); i++) {
	    auto digit = orig_number[i];
	    //print(to_decimal[digit] * pow(base_from, orig_number.length() - i - 1));
    	decimal_number += to_decimal[digit] * pow(base_from, orig_number.length() - i - 1);
	}

	//print(decimal_number);


    i = 0;
    while (decimal_number > 0) {
        res_number += from_decimal[decimal_number % base_to];
        decimal_number /= base_to;
        //print(from_decimal[decimal_number % base_to]);
    }


    /*
	for (auto p : to_decimal) {
    	cout << p.first << ' ' << p.second << endl;
	}
    */


    print(reversed(res_number));

	return 0;
}
