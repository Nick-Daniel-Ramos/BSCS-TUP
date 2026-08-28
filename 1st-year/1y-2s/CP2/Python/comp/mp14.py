import os

MAX = 5
records = []

def main():

    load_records()

    while True:
        match(menu()):
            case 1:
                name = input("Enter name: ")
                quiz_1 = int(input("Enter quiz 1: "))
                quiz_2 = int(input("Enter quiz 2: "))
                quiz_3 = int(input("Enter quiz 3: "))
                add_record(name, quiz_1, quiz_2, quiz_3)
            case 2:
                name = input("Enter name: ")
                del_record(name)
            case 3:
                name = input("Enter name: ")
                update(name)
            case 4:
                display()
            case 5:
                print("Exiting...")
                save_records()
                break
            case _:
                print("Invalid input, [1-4] only")
                os.system("pause")

def locate(name):
    for i, record in enumerate(records):
        if record["name"] == name:
            return i
    return -1

def is_empty():
    return len(records) == 0

def is_full():
    return len(records) == MAX

def average(q1, q2, q3):
    return float((q1 + q2 + q3) / 3.0)

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

def add_record(name, q1, q2, q3):
    if is_full():
        print("Record is Full")
    elif locate(name)!=-1:
        print("Record already exists")
    else:
        student = {
            "name": name,
            "quiz_1": q1,
            "quiz_2": q2,
            "quiz_3": q3
        }
        records.append(student)
        print("Record added")
    os.system("pause")

def del_record(name):
    if is_empty():
        print("Record is Empty")
    else:
        pos = locate(name)
        if pos==-1:
            print("Record not found")
        else:
            for student in records:
                if student["name"] == name:
                    records.remove(student)
            print("Record deleted")
    os.system("pause")

def update(name):
    if is_empty():
        print("Record is Empty")
    else:
        pos = locate(name)
        if pos==-1:
            print("Record not found")
        else:
            while True:
                os.system("cls")

                ave = average(records[pos]["quiz_1"], records[pos]["quiz_2"], records[pos]["quiz_3"])
                print("UPDATE MENU")
                print(f"Record of: {records[pos]['name']}")
                print(f"Quiz 1: {records[pos]['quiz_1']:<10}")
                print(f"Quiz 2: {records[pos]['quiz_2']:<10}")
                print(f"Quiz 3: {records[pos]['quiz_3']:<10}")
                print(f"AVERAGE: {ave:<10.2f}")

                print("UPDATE OPTIONS")
                print("[1] Update Quiz 1")
                print("[2] Update Quiz 2")
                print("[3] Update Quiz 3")
                print("[4] Return to Menu")
                choice = int(input("Enter your choice: "))

                match choice:

                    case 1:
                        records[pos]['quiz_1'] = int(input("Enter new score on quiz 1: "))
                    case 2:
                        records[pos]['quiz_2'] = int(input("Enter new score on quiz 2: "))
                    case 3:
                        records[pos]['quiz_3'] = int(input("Enter new score on quiz 3: "))
                    case 4:
                        break
                    case _:
                        print("Invalid input, [1-4] only")
                        os.system("pause")
                os.system("cls")
            print("Successfully updated")
    os.system("pause")

def save_records():
    with open("records.txt", "w") as file:
        for student in records:
            file.write(f"{student['name']},"
                       f"{student['quiz_1']},"
                       f"{student['quiz_2']},"
                       f"{student['quiz_3']}\n")

def load_records():
    if os.path.exists("records.txt"):
        with open("records.txt", "r") as file:
                for line in file:
                    name, quiz_1, quiz_2, quiz_3 = line.strip().split(",")
                    records.append({"name": name,
                                    "quiz_1": int(quiz_1),
                                    "quiz_2": int(quiz_2),
                                    "quiz_3": int(quiz_3)})

def display():
    os.system("cls")
    if is_empty():
        print("Record is Empty")
    else:
        print(f"{'NO.':<5} {'NAME':<20} {'QUIZ 1':<10} {'QUIZ 2':<10} {'QUIZ 3':<10} {'AVERAGE':<10} {'REMARKS':<10}")

        for i, student in enumerate(records):
            ave = average(student["quiz_1"], student["quiz_2"], student["quiz_3"])

            print(f"{i + 1:<5} {student['name']:<20} "
                  f"{student['quiz_1']:<10} "
                  f"{student['quiz_2']:<10} "
                  f"{student['quiz_3']:<10} "
                  f"{ave:<10.2f} "
                  f"{'PASSED' if ave >= 75 else 'FAILED':<10}")
    os.system("pause")

if __name__ == "__main__":
    main()