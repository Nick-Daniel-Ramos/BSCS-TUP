import random

def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

def print1_n(num):
    if num > 0:
        print1_n(num - 1)
        print(num, end=" ")

def sum_array(arr, idx=0):
    if idx == len(arr):
        return 0
    return arr[idx] + sum_array(arr, idx + 1)

def factorial(num):
    if num == 0 or num == 1:
        return 1
    return num * factorial(num - 1)

def largest(arr, idx=0):
    if idx == len(arr) - 1:
        return arr[idx]
    rest = largest(arr, idx + 1)
    return arr[idx] if arr[idx] > rest else rest

def count_digits(num):
    if num < 10:
        return 1
    return count_digits(num // 10) + 1

def sum_digits(num):
    if num < 10:
        return num
    return num % 10 + sum_digits(num // 10)

def is_palindrome(num, reverse=0, original=-1):
    if original == -1:
        original = num
    if num == 0:
        return original == reverse
    reverse = (reverse * 10) + (num % 10)
    return is_palindrome(num // 10, reverse, original)

def is_sorted(arr, idx=0):
    if idx >= len(arr) - 1:
        return True
    if arr[idx] > arr[idx + 1]:
        return False
    return is_sorted(arr, idx + 1)

def is_prime(num, divisor=2):
    if num < 2:
        return False
    if num == divisor or (divisor * divisor) > num:
        return True
    if num % divisor == 0:
        return False
    return is_prime(num, divisor + 1)

def main():
    number = random.randint(1, 1000)
    fact   = random.randint(1, 15)
    array  = random.sample(range(1, 101), 5)

    print(f"Number : {number}")
    print(f"Fact/N : {fact}")
    print(f"Array  : {array}")
    print("-" * 30)

    print1_n(fact)
    print("")

    print(f"GCD({number}, {fact}) : {gcd(number, fact)}")
    print(f"Sum(array) : {sum_array(array)}")
    print(f"Factorial({fact}) : {factorial(fact)}")
    print(f"Largest(array) : {largest(array)}")
    print(f"Digits({number}) : {count_digits(number)}")
    print(f"SumDig({number}) : {sum_digits(number)}")
    print(f"Palindrome({number}) : {is_palindrome(number)}")
    print(f"Sorted(array) : {is_sorted(array)}")
    print(f"Prime({number}) : {is_prime(number)}")

if __name__ == "__main__":
    main()