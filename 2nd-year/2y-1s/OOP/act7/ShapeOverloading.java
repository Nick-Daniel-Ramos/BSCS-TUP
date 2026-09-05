//RAMOS, NICK DANIEL B.
//BSCS-2A

import java.util.Scanner;

class Shape {

    String shapeName;
    double area;

    // Circle constructor
    Shape(double radius) {
        shapeName = "Circle";
        area = Math.PI * radius * radius;
    }

    // Rectangle constructor
    Shape(int length, int width) {
        shapeName = "Rectangle";
        area = length * width;
    }

    // Square constructor
    Shape(int side) {
        shapeName = "Square";
        area = side * side;
    }

    void display() {
        System.out.println("Shape: " + shapeName);
        System.out.println("Area: " + area);
        System.out.println();
    }
}

public class ShapeOverloading {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter radius for Circle: ");
        double radius = sc.nextDouble();
        Shape circle = new Shape(radius);

        System.out.print("Enter length for Rectangle: ");
        int length = sc.nextInt();
        System.out.print("Enter width for Rectangle: ");
        int width = sc.nextInt();
        Shape rectangle = new Shape(length, width);

        System.out.print("Enter side for Square: ");
        int side = sc.nextInt();
        Shape square = new Shape(side);

        circle.display();
        rectangle.display();
        square.display();

        sc.close();
    }
}
