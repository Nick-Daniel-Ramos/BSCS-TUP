import random

def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)

def print1_n(num):
    if num > 0:
        print1_n(num - 1)
        print(num, end=" ")

def sum_array(arr):
    if len(arr) == 0:
        return 0
    return arr[0] + sum_array(arr[1:])

def factorial(num):
    if num == 1 or num == 0:
        return 1
    return num * factorial(num - 1)

def largest(arr):
    if len(arr) == 1:
        return arr[0]
    else:
        rest = largest(arr[1:])
        if arr[0] > rest:
            return arr[0]
        else:
            return rest

def count_digits(num):
    if num < 10:
        return 1
    else:
        return count_digits(num // 10) + 1 

def sum_digits(num):
    if num < 10:
        return num
    else:
        return num % 10 + sum_digits(num // 10)

def is_palindrome(num, reverse = 0, original = None):
    if original == None:
        original = num

    if num == 0:
        return original == reverse
    
    last = num % 10
    reverse = (reverse * 10) + last
    return is_palindrome(num // 10, reverse, original)

def is_sorted(arr):
    if len(arr) == 0 or len(arr) == 1:
        return True
    if arr[0] > arr[1]:
        return False
    else:
        return is_sorted(arr[1:])

def is_prime(num, divisor = 2):
    if num < 2:
        return False
    if num == divisor:
        return True
    if (divisor*divisor) > num:
        return True
    if num % divisor == 0:
        return False
    return is_prime(num, divisor + 1)

def main():
    number = random.randint(1, 1000)
    fact = random.randint(1, 15)
    array = random.sample(range(1,101), 5)

    print(f"Number: {number}")
    print(f"Factorial/1-n Number: {fact}")
    print(f"Array: {array}")
    print("-"*30)
    print1_n(fact)
    print("")
    print(f"GCD of {number} & {fact}: {gcd(number, fact)}")
    print(f"Sum of array: {sum_array(array)}")
    print(f"Factorial of {fact}: {factorial(fact)}")
    print(f"Largest in array: {largest(array)}")
    print(f"Count digits of {number}: {count_digits(number)}")
    print(f"Sum of digits of {number}: {sum_digits(number)}")
    print(f"is {number} palindrome: {is_palindrome(number)}")
    print(f"is array sorted: {is_sorted(array)}")
    print(f"is {number} prime: {is_prime(number)}")

if __name__ == "__main__":
    main()
