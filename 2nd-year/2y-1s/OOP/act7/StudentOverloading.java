//RAMOS, NICK DANIEL B.
//BSCS-2A

import java.util.Scanner;

class Student {

    int id;
    String name;
    String course;

    // Constructor 1: Only name
    Student(String name) {
        this.name = name;
    }

    // Constructor 2: ID and name
    Student(int id, String name) {
        this.id = id;
        this.name = name;
    }

    // Constructor 3: ID, name, and course
    Student(int id, String name, String course) {
        this.id = id;
        this.name = name;
        this.course = course;
    }

    void display() {
        System.out.println(id + " " + name + " " + course);
    }
}

public class StudentOverloading {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter name for Student 1: ");
        String name1 = sc.nextLine();
        Student s1 = new Student(name1);

        System.out.print("Enter ID for Student 2: ");
        int id2 = sc.nextInt();
        sc.nextLine();
        System.out.print("Enter name for Student 2: ");
        String name2 = sc.nextLine();
        Student s2 = new Student(id2, name2);

        System.out.print("Enter ID for Student 3: ");
        int id3 = sc.nextInt();
        sc.nextLine();
        System.out.print("Enter name for Student 3: ");
        String name3 = sc.nextLine();
        System.out.print("Enter course for Student 3: ");
        String course3 = sc.nextLine();
        Student s3 = new Student(id3, name3, course3);

        s1.display();
        s2.display();
        s3.display();

        sc.close();
    }
}
