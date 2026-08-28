import random
import os

num = random.randint(1, 100)

answer = 0

guess = []
while answer != num:
    answer = int(input("Guess the number from 1 - 100: "))
    if answer in guess:
        print("Duplicated")
    else:
        guess.append(answer)
        if answer == num:
            print(f"That's correct the number is {num}")
        elif answer < num:
            print("Higher")
        else:
            print("Lower")
    
print(guess)

counter = len(guess)

print(f"You guessed {counter} {'time' if counter == 1 else 'times'} ")