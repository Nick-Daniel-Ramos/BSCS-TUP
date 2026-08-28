/* Write the recursive functions of the following:
1. Write a recursive function to compute the factorial of a number.
2. Reverse digits recursively. Ex. 1234 output: 4321
3. Check if a number is palindrome that is it reads the same forward and
backward. Ex. 121 is palindrome Write your own strlen() using recursion that
returns the length of of a string. Tower of Hanoi Include a menu to choose from
the 5 problems. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define array_size 128

int fact(int num) {
  if (num == 0) {
    return 1;
  } else {
    return num * fact(num - 1);
  }
}

int reverse(int num, int reversed_num) {
  if (num == 0) {
    return reversed_num;
  }
  int temp = num % 10;
  reversed_num = (reversed_num * 10) + temp;
  return reverse(num / 10, reversed_num);
}

void palindrome(int num) {
  int reversed_num = reverse(num, 0);
  if (reversed_num == num) {
    printf("%d is a Palindrome number\n", reversed_num);
  } else {
    printf("%d is not a Palindrome number\n", reverse(reversed_num, 0));
  }
}

int str_len(char *str) {
  if (*str == '\0') {
    return 0;
  }
  return 1 + str_len(str + 1);
}

void tower_of_hanoi(int n, char source, char to, char destination) {
  if (n == 1) {
    printf("Move disk 1 from %c to %c\n", source, destination);
    return;
  }
  tower_of_hanoi(n - 1, source, destination, to);
  printf("Move disk %d from %c to %c\n", n, source, destination);
  tower_of_hanoi(n - 1, to, source, destination);
}

void flush_input() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

int menu() {
  int choice;
  system("cls");
  printf("\n1. Factorial\n");
  printf("2. Reverse\n");
  printf("3. Palindrome\n");
  printf("4. String Length\n");
  printf("5. Tower of Hanoi\n");
  printf("6. Exit\n");
  printf("Enter your choice: ");
  if (scanf("%d", &choice) != 1) {
    flush_input();
    return -1;
  }
  flush_input();
  return choice;
}

int main() {
  int choice;
  int num = 0;
  char str[array_size];

  while (choice != 6) {
    choice = menu();
    switch (choice) {
    case 1:
      printf("Enter a number: ");
      scanf("%d", &num);
      printf("Factorial: %d\n", fact(num));
      system("pause");
      break;
    case 2:
      num = 0;
      printf("Enter a number: ");
      scanf("%d", &num);
      printf("Reverse: %d\n", reverse(num, 0));
      system("pause");
      break;
    case 3:
      num = 0;
      printf("Enter a number: ");
      scanf("%d", &num);
      palindrome(num);
      system("pause");
      break;
    case 4:
      printf("Enter a string: ");
      fgets(str, array_size, stdin);
      str[strcspn(str, "\n")] = '\0';
      printf("String Length: %d\n", str_len(str));
      system("pause");
      break;
    case 5:
      printf("Enter the number of disks: ");
      scanf("%d", &num);
      tower_of_hanoi(num, 'A', 'B', 'C');
      system("pause");
      break;
    case 6:
      printf("Exit\n");
      break;
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}
