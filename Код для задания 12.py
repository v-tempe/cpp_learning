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
        user_answer = input()
    except:
        print("Введённое вами значение некорректно. Пожалуйста, введите новое.")
    else:
        if (user_answer.upper() == "YES") or (user_answer.upper() == "NO"):
            successful_input = True
        else:
            print("Введённое вами значение некорректно. Пожалуйста, введите новое.")

