def printN(num):
    if num == 0:
        return
    
    print(num, end=" ")
    return printN(num - 1)

def is_palindrome(name):
    name = name.lower()
    if len(name) <= 1:
        return True

    if name[0] != name[-1]:
        return False

    return is_palindrome(name[1:-1])

def sum_N(num):
    if num <= 1:
        return num

    return num + sum_N(num - 1)

def reverse(name):
    if len(name) <= 1:
        return name
    
    return name[-1] + reverse(name[:-1])

def sum_E(arr):
    if len(arr) == 0:
        return 0
    
    return arr[0] + sum_E(arr[1:])

def count_occ(arr, target):
    if len(arr) == 0:
        return 0
    if arr[0] == target:
        return 1 + count_occ(arr[1:], target)
    
    return count_occ(arr[1:], target)

def count_vowel(name):
    if len(name) == 0:
        return 0

    return 1 + count_vowel(name[1:])

def fib(num):
    if num <= 1:
        return 0
    if num == 2:
        return 1
    
    return fib(num - 1) + fib(num - 2)
