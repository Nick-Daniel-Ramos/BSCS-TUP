import os


class Student:
    def __init__(self, name, q1, q2, q3):
        self.name = name
        self.q1 = q1
        self.q2 = q2
        self.q3 = q3
    @property
    def average(self):
        return (self.q1 + self.q2 + self.q3) / 3.0

class RecordManager:

    def __init__(self):
        self.MAX = 5
        self.records = []

    def add_record(self, name, q1, q2, q3):
        if self.is_full():
            print("Record is Full")
        elif self.locate(name)!=-1:
            print("Record already exists")
        else:
            stud = Student(name, q1, q2, q3)
            self.records.append(stud)
            print("Record added")
        os.system("pause")

    def del_record(self, name):
        if self.is_empty():
            print("Record is Empty")
        else:
            pos = self.locate(name)
            if pos==-1:
                print("Record not found")
            else:
                for student in self.records:
                    if student.name == name:
                        self.records.remove(student)
                print("Record deleted")
        os.system("pause")

    def update(self, name):
        if self.is_empty():
            print("Record is Empty")
        else:
            pos = self.locate(name)
            if pos==-1:
                print("Record not found")
            else:
                while True:
                    os.system("cls")

                    ave = self.records[pos].average
                    print("UPDATE MENU")
                    print(f"Record of: {self.records[pos].name}")
                    print(f"Quiz 1: {self.records[pos].q1:<10}")
                    print(f"Quiz 2: {self.records[pos].q2:<10}")
                    print(f"Quiz 3: {self.records[pos].q3:<10}")
                    print(f"AVERAGE: {ave:<10.2f}")
                    print("-"*20)
                    print("UPDATE OPTIONS")
                    print("[1] Update Quiz 1")
                    print("[2] Update Quiz 2")
                    print("[3] Update Quiz 3")
                    print("[4] Return to Menu")
                    choice = int(input("Enter your choice: "))

                    match choice:

                        case 1:
                            self.records[pos].q1 = int(input("Enter new score on quiz 1: "))
                        case 2:
                            self.records[pos].q2 = int(input("Enter new score on quiz 2: "))
                        case 3:
                            self.records[pos].q3 = int(input("Enter new score on quiz 3: "))
                        case 4:
                            break
                        case _:
                            print("Invalid input, [1-4] only")
                            os.system("pause")
                    os.system("cls")
                print("Successfully updated")
        os.system("pause")

    def save_records(self):
        with open("records.txt", "w") as file:
            for student in self.records:
                file.write(f"{student.name},"
                        f"{student.q1},"
                        f"{student.q2},"
                        f"{student.q3}\n")

    def load_records(self):
        if os.path.exists("records.txt"):
            with open("records.txt", "r") as file:
                    for line in file:
                        name, q1, q2, q3 = line.strip().split(",")
                        stud_obj = Student(name, int(q1), int(q2), int(q3))
                        self.records.append(stud_obj)

    def display(self):
        os.system("cls")
        if self.is_empty():
            print("Record is Empty")
        else:
            print(f"{'NO.':<5} {'NAME':<20} {'QUIZ 1':<10} {'QUIZ 2':<10} {'QUIZ 3':<10} {'AVERAGE':<10} {'REMARKS':<10}")

            for i, student in enumerate(self.records):
                ave = student.average

                print(f"{i + 1:<5} {student.name:<20} "
                    f"{student.q1:<10} "
                    f"{student.q2:<10} "
                    f"{student.q3:<10} "
                    f"{ave:<10.2f} "
                    f"{'PASSED' if ave >= 75 else 'FAILED':<10}")
        os.system("pause")
    
    def locate(self, name):
        for i, record in enumerate(self.records):
            if record.name == name:
                return i
        return -1

    def is_empty(self):
        return len(self.records) == 0

    def is_full(self):
        return len(self.records) == self.MAX

def main():

    manager = RecordManager()
    manager.load_records()

    def menu():
        os.system("cls")
        print("MENU")
        print("[1] Add Record")
        print("[2] Delete Record")
        print("[3] Update Record")
        print("[4] Display Records")
        print("[5] Exit")
        choice = int(input("Enter your choice: "))
        return choice

    while True:
        match(menu()):
            case 1:
                name = input("Enter name: ")
                quiz_1 = int(input("Enter quiz 1: "))
                quiz_2 = int(input("Enter quiz 2: "))
                quiz_3 = int(input("Enter quiz 3: "))
                manager.add_record(name, quiz_1, quiz_2, quiz_3)
            case 2:
                name = input("Enter name: ")
                manager.del_record(name)
            case 3:
                name = input("Enter name: ")
                manager.update(name)
            case 4:
                manager.display()
            case 5:
                print("Exiting...")
                manager.save_records()
                break
            case _:
                print("Invalid input, [1-4] only")
                os.system("pause")

if __name__ == "__main__":
    main()