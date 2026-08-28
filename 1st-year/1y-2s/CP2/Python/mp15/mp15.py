import os
import random

def addition(number):
    counter = 0
    for i in range(number):
        num1 = random.randint(1, 20)
        num2 = random.randint(1, 20)
        correct = num1 + num2
        try:
            answer = int(input(f"What is {num1} + {num2}?: "))
        except ValueError:
            print("Invalid Input")
            continue
        if answer != correct:
            print(f"Incorrect. The answer is {correct}")
        else:
            print("Correct!")
            counter += 1
        print("-"*32)
        print(f"Score: {counter} / {number}")
        print("-"*32)
    return counter

def subtraction(number):
    counter = 0
    for i in range(number):
        num1 = random.randint(1, 20)
        num2 = random.randint(1, 20)
        if num1 <= num2:
            temp = num1
            num1 = num2
            num2 = temp
        correct = num1 - num2
        try:
            answer = int(input(f"What is {num1} - {num2}?: "))
        except ValueError:
            print("Invalid Input")
            continue
        if answer != correct:
            print(f"Incorrect. The answer is {correct}")
        else:
            print("Correct!")
            counter += 1
        print("-"*32)
        print(f"Score: {counter} / {number}")
        print("-"*32)
    return counter

def multiplication(number):
    counter = 0
    for i in range(number):
        num1 = random.randint(1, 20)
        num2 = random.randint(1, 20)
        correct = num1 * num2
        try:
            answer = int(input(f"What is {num1} * {num2}?: "))
        except ValueError:
            print("Invalid Input")
            continue
        if answer != correct:
            print(f"Incorrect. The answer is {correct}")
        else:
            print("Correct!")
            counter += 1
        print("-"*32)
        print(f"Score: {counter} / {number}")
        print("-"*32)
    return counter

def division(number):
    counter = 0
    for i in range(number):
        num1 = random.randint(1, 20)
        num2 = random.randint(1, 20)
        while num1 % num2 != 0:
            num2 = random.randint(1, 20)
        correct = num1 // num2
        try:
            answer = int(input(f"What is {num1} / {num2}?: "))
        except ValueError:
            print("Invalid Input")
            continue
        if answer != correct:
            print(f"Incorrect. The answer is {correct}")
        else:
            print("Correct!")
            counter += 1
        print("-"*32)
        print(f"Score: {counter} / {number}")
        print("-"*32)
    return counter

def menu():
    os.system("cls")
    print("ARITHMETIC PRACTICE PROGRAM")
    print("-"*32)
    print("[1] Addition")
    print("[2] Subtraction")
    print("[3] Multiplication")
    print("[4] Division")
    print("[5] Exit")
    try:
        choice = int(input("Select [1-5] only: "))
    except ValueError:
        return -1
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
                print("Exiting...")
                os.system("pause")
                break
            case _:
                print("Invalid option, [1-5] only")
                os.system("pause")
                continue

if __name__ == "__main__":
    main()