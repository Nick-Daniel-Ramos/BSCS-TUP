import java.util.Scanner;

public class Act3 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("FARMER INFORMATION FORM");

        System.out.print("Name: ");
        String name = input.nextLine();

        System.out.print("Age: ");
        int age = Integer.parseInt(input.nextLine());

        System.out.print("Height (cm): ");
        double height = Double.parseDouble(input.nextLine());

        System.out.print("Weight (kg): ");
        double weight = Double.parseDouble(input.nextLine());

        System.out.print("Farm Location: ");
        String farmLocation = input.nextLine();

        System.out.print("Years of Experience: ");
        int yearsOfExperience = Integer.parseInt(input.nextLine());

        System.out.print("Crops Planted (number): ");
        int cropsPlanted = Integer.parseInt(input.nextLine());

        System.out.print("Farm Size (hectares): ");
        double farmSize = Double.parseDouble(input.nextLine());

        System.out.print("Tools Owned (comma-separated): ");
        String toolsOwned = input.nextLine();

        System.out.print("Income: ");
        double income = Double.parseDouble(input.nextLine());

        System.out.println("\nFARMER INFORMATION");
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

        input.close();
    }
}