from string import ascii_uppercase as english_uppercase_letters
from random import choice


vowels = "AEIOUY"


def are_all_english_digits(word: str):
    for i in range(4):
        if word[i] not in english_uppercase_letters:
            return False
    return True


def generate_word():
    word = str()
    
    for _ in range(4):
        word += choice(english_uppercase_letters)
    
    return word


def vowels_count(word: str):
    count = 0
    
    for i in range(4):
        if word[i] in vowels:
            count += 1
    
    return count


def bubble_sort(arr):
    n = len(arr)
    for k in range(n, 1, -1):
        for i in range(k-1):
            if arr[i] > arr[i+1]:
                arr[i], arr[i+1] = arr[i+1], arr[i]


print("Пожалуйста, введите целое число в диапазоне [2; 5]")

M = int()
successful_input = False
while not successful_input:
    try:
        M = int(input())
    except:
        print("Введённое вами значение некорректно. Пожалуйста, введите новое.")
    else:
        if 2 <= M <= 5:
            successful_input = True
        else:
            print("Введённое вами число должно быть в диапазоне [2; 5]")
            print("Пожалуйста, введите новое.")


# Итак, мы ввели подходящее нам число

print("Вы хотите вводить слова самостоятельно?")

user_answer = str()
successful_input = False
while not successful_input:
    try:
        user_answer = input().upper()
    except:
        print("Введённое вами значение некорректно. Пожалуйста, введите новое.")
    else:
        if (user_answer == "YES") or (user_answer == "NO"):
            successful_input = True
        else:
            print("Введённое вами значение некорректно. Пожалуйста, введите новое.")


# Итак, мы добились от пользователя ответа, хочет ли он вводить числа самостоятельно

matr = [[0 for _ in range(M)] for _ in range(M)]

W = str()

if user_answer == "YES":  # пользователь вводит
    print("Вводите")
    for i in range(M):
        for j in range(M):
            successful_input = False
            while not successful_input:
                try:
                    word = input().upper()
                except:
                    print("Введённое вами слово некорректно. Пожалуйста, введите новое.")
                else:
                    if len(word) == 4:
                        if are_all_english_digits(word):
                            successful_input = True
                            matr[i][j] = word
                        else:
                            print("Слово должно состоять только из букв английского алфавита.")
                            print("Пожалуйста, введите новое.")
                    else:
                        print("Слова должно состоять ровно из 4-х букв.")
                        print("Пожалуйста, введите новое.")

else:  # генерируем сами
    for i in range(M):
        for j in range(M):
            matr[i][j] = generate_word()


# Итак, мы создали матрицу

arr = list()

for i in range(M):
    for j in range(M):
        vc = vowels_count(matr[i][j])
        arr.append(vc)


# Всё, массив готов. Осталось только отсортировать его

bubble_sort(arr)

print(arr)





