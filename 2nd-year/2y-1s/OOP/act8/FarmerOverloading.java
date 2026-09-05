//RAMOS, NICK DANIEL B.
//BSCS-2A

import java.util.Scanner;

class Farmer {

    String name;
    int age;
    double height;
    double weight;
    String farmLocation;
    int yearsOfExperience;
    int cropsPlanted;
    double farmSize;
    String toolsOwned;
    double income;

    // Constructor 1: Default (blank record)
    Farmer() {
        this.name = "Unknown";
        this.age = 0;
        this.height = 0.0;
        this.weight = 0.0;
        this.farmLocation = "Not Set";
        this.yearsOfExperience = 0;
        this.cropsPlanted = 0;
        this.farmSize = 0.0;
        this.toolsOwned = "None";
        this.income = 0.0;
    }

    // Constructor 2: Basic personal info
    Farmer(String name, int age, double height, double weight) {
        this.name = name;
        this.age = age;
        this.height = height;
        this.weight = weight;
        this.farmLocation = "Not Set";
        this.yearsOfExperience = 0;
        this.cropsPlanted = 0;
        this.farmSize = 0.0;
        this.toolsOwned = "None";
        this.income = 0.0;
    }

    // Constructor 3: Personal info + farm identity
    Farmer(String name, int age, double height, double weight,
           String farmLocation, int yearsOfExperience) {
        this.name = name;
        this.age = age;
        this.height = height;
        this.weight = weight;
        this.farmLocation = farmLocation;
        this.yearsOfExperience = yearsOfExperience;
        this.cropsPlanted = 0;
        this.farmSize = 0.0;
        this.toolsOwned = "None";
        this.income = 0.0;
    }

    // Constructor 4: + farming details
    Farmer(String name, int age, double height, double weight,
           String farmLocation, int yearsOfExperience,
           int cropsPlanted, double farmSize) {
        this.name = name;
        this.age = age;
        this.height = height;
        this.weight = weight;
        this.farmLocation = farmLocation;
        this.yearsOfExperience = yearsOfExperience;
        this.cropsPlanted = cropsPlanted;
        this.farmSize = farmSize;
        this.toolsOwned = "None";
        this.income = 0.0;
    }

    // Constructor 5: Full details
    Farmer(String name, int age, double height, double weight,
           String farmLocation, int yearsOfExperience,
           int cropsPlanted, double farmSize,
           String toolsOwned, double income) {
        this.name = name;
        this.age = age;
        this.height = height;
        this.weight = weight;
        this.farmLocation = farmLocation;
        this.yearsOfExperience = yearsOfExperience;
        this.cropsPlanted = cropsPlanted;
        this.farmSize = farmSize;
        this.toolsOwned = toolsOwned;
        this.income = income;
    }

    void display() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Height: " + height + " cm");
        System.out.println("Weight: " + weight + " kg");
        System.out.println("Farm Location: " + farmLocation);
        System.out.println("Years of Experience: " + yearsOfExperience);
        System.out.println("Crops Planted: " + cropsPlanted);
        System.out.println("Farm Size: " + farmSize + " hectares");
        System.out.println("Tools Owned: " + toolsOwned);
        System.out.println("Income: " + income);
        System.out.println();
    }
}

public class FarmerOverloading {
    private static String readNonEmpty(Scanner input, String prompt) {
        String value;
        do {
            System.out.print(prompt);
            value = input.nextLine().trim();
            if (value.isEmpty()) {
                System.out.println("This field cannot be blank. Try again.");
            }
        } while (value.isEmpty());
        return value;
    }

    private static int readIntInRange(Scanner input, String prompt, int min, int max) {
        int value;
        while (true) {
            System.out.print(prompt);
            value = input.nextInt();
            input.nextLine();
            if (value < min || value > max) {
                System.out.println("Enter a value between " + min + " and " + max + ".");
            } else {
                break;
            }
        }
        return value;
    }

    private static double readDoubleInRange(Scanner input, String prompt, double min, double max) {
        double value;
        while (true) {
            System.out.print(prompt);
            value = input.nextDouble();
            input.nextLine();
            if (value < min || value > max) {
                System.out.println("Enter a value between " + min + " and " + max + ".");
            } else {
                break;
            }
        }
        return value;
    }

    private static int readYearsOfExperience(Scanner input, int age) {
        int years;
        while (true) {
            System.out.print("Enter Years of Experience: ");
            years = input.nextInt();
            input.nextLine();
            if (years < 0 || years > age) {
                System.out.println("Years of Experience cannot be negative or greater than Age (" + age + "). Try again.");
            } else {
                break;
            }
        }
        return years;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int choice = -1;

        while (choice != 0) {
            System.out.println("Farmer Registration System");
            System.out.println("[1] No details (blank record)");
            System.out.println("[2] Basic personal info (Name, Age, Height, Weight)");
            System.out.println("[3] + Farm identity (Farm Location, Years of Experience)");
            System.out.println("[4] + Farming details (Crops Planted, Farm Size)");
            System.out.println("[5] Full details (+ Tools Owned, Income)");
            System.out.println("[0] Exit");
            System.out.print("Enter choice: ");
            choice = input.nextInt();
            input.nextLine();

            Farmer farmer;

            switch (choice) {
                case 1:
                    farmer = new Farmer();
                    farmer.display();
                    break;

                case 2:
                    String name2 = readNonEmpty(input, "Enter Name: ");
                    int age2 = readIntInRange(input, "Enter Age: ", 1, 120);
                    double height2 = readDoubleInRange(input, "Enter Height (cm): ", 50, 250);
                    double weight2 = readDoubleInRange(input, "Enter Weight (kg): ", 2, 300);
                    farmer = new Farmer(name2, age2, height2, weight2);
                    farmer.display();
                    break;

                case 3:
                    String name3 = readNonEmpty(input, "Enter Name: ");
                    int age3 = readIntInRange(input, "Enter Age: ", 1, 120);
                    double height3 = readDoubleInRange(input, "Enter Height (cm): ", 50, 250);
                    double weight3 = readDoubleInRange(input, "Enter Weight (kg): ", 2, 300);
                    String farmLocation3 = readNonEmpty(input, "Enter Farm Location: ");
                    int years3 = readYearsOfExperience(input, age3);
                    farmer = new Farmer(name3, age3, height3, weight3, farmLocation3, years3);
                    farmer.display();
                    break;

                case 4:
                    String name4 = readNonEmpty(input, "Enter Name: ");
                    int age4 = readIntInRange(input, "Enter Age: ", 1, 120);
                    double height4 = readDoubleInRange(input, "Enter Height (cm): ", 50, 250);
                    double weight4 = readDoubleInRange(input, "Enter Weight (kg): ", 2, 300);
                    String farmLocation4 = readNonEmpty(input, "Enter Farm Location: ");
                    int years4 = readYearsOfExperience(input, age4);
                    int crops4 = readIntInRange(input, "Enter Crops Planted: ", 0, Integer.MAX_VALUE);
                    double size4 = readDoubleInRange(input, "Enter Farm Size (hectares): ", 0.1, 1000000);
                    farmer = new Farmer(name4, age4, height4, weight4, farmLocation4, years4, crops4, size4);
                    farmer.display();
                    break;

                case 5:
                    String name5 = readNonEmpty(input, "Enter Name: ");
                    int age5 = readIntInRange(input, "Enter Age: ", 1, 120);
                    double height5 = readDoubleInRange(input, "Enter Height (cm): ", 50, 250);
                    double weight5 = readDoubleInRange(input, "Enter Weight (kg): ", 2, 300);
                    String farmLocation5 = readNonEmpty(input, "Enter Farm Location: ");
                    int years5 = readYearsOfExperience(input, age5);
                    int crops5 = readIntInRange(input, "Enter Crops Planted: ", 0, Integer.MAX_VALUE);
                    double size5 = readDoubleInRange(input, "Enter Farm Size (hectares): ", 0.1, 1000000);
                    String tools5 = readNonEmpty(input, "Enter Tools Owned (comma-separated): ");
                    double income5 = readDoubleInRange(input, "Enter Income: ", 0, Double.MAX_VALUE);
                    farmer = new Farmer(name5, age5, height5, weight5, farmLocation5, years5, crops5, size5, tools5, income5);
                    farmer.display();
                    break;

                case 0:
                    System.out.println("Exiting Farmer Registration System.");
                    break;

                default:
                    System.out.println("Invalid choice. Try again.");
            }
        }
        input.close();
    }
}