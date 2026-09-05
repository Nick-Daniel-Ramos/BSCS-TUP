//RAMOS, NICK DANIEL B.
//BSCS-2A

import java.util.Scanner;

class Account {

    int accNum;
    String accHold;
    double balance;
    String accType;
    double intRate;

    // Constructor 1: Default
    Account() {
        this.accNum = 0;
        this.accHold = "Unknown";
        this.balance = 0.0;
        this.accType = "Not Set";
        this.intRate = 0.0;
    }

    // Constructor 2: Account number only
    Account(int accNum) {
        this.accNum = accNum;
        this.accHold = "Unknown";
        this.balance = 0.0;
        this.accType = "Not Set";
        this.intRate = 0.0;
    }

    // Constructor 3: Account number and holder
    Account(int accNum, String accHold) {
        this.accNum = accNum;
        this.accHold = accHold;
        this.balance = 0.0;
        this.accType = "Not Set";
        this.intRate = 0.0;
    }

    // Constructor 4: Account number, holder, initial balance
    Account(int accNum, String accHold, double balance) {
        this.accNum = accNum;
        this.accHold = accHold;
        this.balance = balance;
        this.accType = "Not Set";
        this.intRate = 0.0;
    }

    // Constructor 5: Account number, holder, balance, account type
    Account(int accNum, String accHold, double balance, String accType) {
        this.accNum = accNum;
        this.accHold = accHold;
        this.balance = balance;
        this.accType = accType;
        this.intRate = 0.0;
    }

    // Constructor 6: Full details, interest rate
    Account(int accNum, String accHold, double balance, String accType, double intRate) {
        this.accNum = accNum;
        this.accHold = accHold;
        this.balance = balance;
        this.accType = accType;
        this.intRate = intRate;
    }

    void display() {
        System.out.println("Account Number : " + accNum);
        System.out.println("Account Holder : " + accHold);
        System.out.println("Balance        : " + balance);
        System.out.println("Account Type   : " + accType);
        System.out.println("Interest Rate  : " + intRate + "%");
        System.out.println();
    }
}

public class AccountOverloading {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice = -1;

        while (choice != 0) {
            System.out.println("Online Banking System");
            System.out.println("1 - No details (blank account)");
            System.out.println("2 - Account Number only");
            System.out.println("3 - Account Number + Holder Name");
            System.out.println("4 - Account Number + Holder Name + Balance");
            System.out.println("5 - Account Number + Holder Name + Balance + Account Type");
            System.out.println("6 - Full details (+ Interest Rate)");
            System.out.println("0 - Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();
            sc.nextLine();

            Account account;

            switch (choice) {
                case 1:
                    account = new Account();
                    account.display();
                    break;

                case 2:
                    System.out.print("Enter Account Number: ");
                    int accNum2 = sc.nextInt();
                    account = new Account(accNum2);
                    account.display();
                    break;

                case 3:
                    System.out.print("Enter Account Number: ");
                    int accNum3 = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Enter Account Holder Name: ");
                    String holder3 = sc.nextLine();
                    account = new Account(accNum3, holder3);
                    account.display();
                    break;

                case 4:
                    System.out.print("Enter Account Number: ");
                    int accNum4 = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Enter Account Holder Name: ");
                    String holder4 = sc.nextLine();
                    System.out.print("Enter Initial Balance: ");
                    double balance4 = sc.nextDouble();
                    account = new Account(accNum4, holder4, balance4);
                    account.display();
                    break;

                case 5:
                    System.out.print("Enter Account Number: ");
                    int accNum5 = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Enter Account Holder Name: ");
                    String holder5 = sc.nextLine();
                    System.out.print("Enter Initial Balance: ");
                    double balance5 = sc.nextDouble();
                    sc.nextLine();
                    System.out.print("Enter Account Type (Savings/Checking): ");
                    String type5 = sc.nextLine();
                    account = new Account(accNum5, holder5, balance5, type5);
                    account.display();
                    break;

                case 6:
                    System.out.print("Enter Account Number: ");
                    int accNum6 = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Enter Account Holder Name: ");
                    String holder6 = sc.nextLine();
                    System.out.print("Enter Initial Balance: ");
                    double balance6 = sc.nextDouble();
                    sc.nextLine();
                    System.out.print("Enter Account Type (Savings/Checking): ");
                    String type6 = sc.nextLine();
                    System.out.print("Enter Interest Rate (%): ");
                    double rate6 = sc.nextDouble();
                    account = new Account(accNum6, holder6, balance6, type6, rate6);
                    account.display();
                    break;

                case 0:
                    System.out.println("Exiting Online Banking System.");
                    break;

                default:
                    System.out.println("Invalid choice. Try again.");
            }
        }
        sc.close();
    }
}