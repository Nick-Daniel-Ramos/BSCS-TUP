import os
import random

def addition(number):
    counter = 0
    for i in range(number):
        num1, num2 = number_generator()
        correct = num1 + num2

        answer = int(input(f"What is {num1} + {num2}?: "))

        if answer != correct:
            print(f"Incorrect answer. the answer is {correct}")
        else:
            print(f"Correct answer. the answer is {correct}")
            counter = counter + 1
    return counter

def subtraction(number):
    counter = 0
    for i in range(number):
        num1, num2 = number_generator()
        if num1 <= num2:
            temp = num1
            num1 = num2
            num2 = temp
        correct = num1 - num2

        answer = int(input(f"What is {num1} - {num2}?: "))
        if answer != correct:
            print(f"Incorrect answer. the answer is {correct}")
        else:
            print(f"Correct answer. the answer is {correct}")
            counter = counter + 1
    return counter

def multiplication(number):
    counter = 0
    for i in range(number):
        num1, num2 = number_generator()
        correct = num1 * num2
        answer = int(input(f"What is {num1} * {num2}?: "))
        if answer != correct:
            print(f"Incorrect answer. the answer is {correct}")
        else:
            print(f"Correct answer. the answer is {correct}")
            counter = counter + 1
    return counter

def division(number):
    correct = 0
    counter = 0
    for i in range(number):
        num1, num2 = number_generator()
        while num1 % num2 != 0:
            num1, num2 = number_generator()
            correct = num1 // num2

        answer = int(input(f"What is {num1} / {num2}?: "))
        if answer != correct:
            print(f"Incorrect answer. the answer is {correct}")
        else:
            print(f"Correct answer. the answer is {correct}")
            counter = counter + 1
    return counter

def number_generator():
    random.seed()
    number1 = int(random.randint(1, 20))
    number2 = int(random.randint(1, 20))
    return number1, number2

def menu():
    os.system("cls")

    print("ARITHMETIC PRACTICE PROGRAM")
    print("[1] Addition")
    print("[2] Subtraction")
    print("[3] Multiplication")
    print("[4] Division")
    print("[5] Exit")
    choice = int(input("Enter your choice: "))
    os.system("cls")
    return choice

def main():
    n_times = 5

    while True:
        match(menu()):
            case 1:
                print(f"You got {addition(n_times)} out of {n_times}")
                os.system("pause")
            case 2:
                print(f"You got {subtraction(n_times)} out of {n_times}")
                os.system("pause")
            case 3:
                print(f"You got {multiplication(n_times)} out of {n_times}")
                os.system("pause")
            case 4:
                print(f"You got {division(n_times)} out of {n_times}")
                os.system("pause")
            case 5:
                exit(0)
            case _:
                print("Invalid option, [1-4] only")
                os.system("pause")

if __name__ == "__main__":
    main()