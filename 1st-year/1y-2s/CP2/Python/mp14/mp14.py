import os

MAX = 5
records = []

def main():
    retrieve()
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
                save()
                break
            case _:
                print("Invalid input, [1-5] only")
                os.system("pause")

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

def average(q1, q2, q3):
    return float((q1 + q2 + q3) / 3.0)

def add_record(name, q1, q2, q3):
    if len(records) == MAX:
        print("Record is Full")
        os.system("pause")
        return
    for record in records:
        if record["name"] == name:
            print("Record already exists")
            os.system("pause")
            return
    records.append({"name": name, "quiz_1": q1, "quiz_2": q2, "quiz_3": q3})
    records.sort(key=lambda r: r["name"])
    print("Record added")
    os.system("pause")

def del_record(name):
    if len(records) == 0:
        print("Record is Empty")
        os.system("pause")
        return
    for record in records:
        if record["name"] == name:
            records.remove(record)
            print("Record deleted")
            os.system("pause")
            return
    print("Record not found")
    os.system("pause")

def update(name):
    if len(records) == 0:
        print("Record is Empty")
        os.system("pause")
        return
    for record in records:
        if record["name"] == name:
            while True:
                os.system("cls")
                ave = average(record["quiz_1"], record["quiz_2"], record["quiz_3"])
                print("UPDATE MENU")
                print(f"Record of: {record['name']}")
                print(f"Quiz 1: {record['quiz_1']:<10}")
                print(f"Quiz 2: {record['quiz_2']:<10}")
                print(f"Quiz 3: {record['quiz_3']:<10}")
                print(f"AVERAGE: {ave:<10.2f}")
                print("UPDATE OPTIONS")
                print("[1] Update Quiz 1")
                print("[2] Update Quiz 2")
                print("[3] Update Quiz 3")
                print("[4] Return to Menu")
                choice = int(input("Enter your choice: "))
                match choice:
                    case 1:
                        record["quiz_1"] = int(input("Enter new score on quiz 1: "))
                    case 2:
                        record["quiz_2"] = int(input("Enter new score on quiz 2: "))
                    case 3:
                        record["quiz_3"] = int(input("Enter new score on quiz 3: "))
                    case 4:
                        break
                    case _:
                        print("Invalid input, [1-4] only")
                        os.system("pause")
                print("Successfully Updated")
                os.system("pause")
            print("Exiting...")
            os.system("pause")
            return
    print("Record not found")
    os.system("pause")

def display():
    os.system("cls")
    if len(records) == 0:
        print("Record is Empty")
        os.system("pause")
        return
    print(f"{'NO.':<5} {'NAME':<20} {'QUIZ 1':<10} {'QUIZ 2':<10} {'QUIZ 3':<10} {'AVERAGE':<10} {'REMARKS':<10}")
    i = 0
    for student in records:
        ave = average(student["quiz_1"], student["quiz_2"], student["quiz_3"])
        i += 1
        print(f"{i:<5} {student['name']:<20} "
              f"{student['quiz_1']:<10} "
              f"{student['quiz_2']:<10} "
              f"{student['quiz_3']:<10} "
              f"{ave:<10.2f} "
              f"{'PASSED' if ave >= 75 else 'FAILED':<10}")
    os.system("pause")

def save():
    with open("records.txt", "w") as file:
        for student in records:
            file.write(f"{student['name']},"
                       f"{student['quiz_1']},"
                       f"{student['quiz_2']},"
                       f"{student['quiz_3']}\n")

def retrieve():
    if os.path.exists("records.txt"):
        with open("records.txt", "r") as file:
            for line in file:
                name, quiz_1, quiz_2, quiz_3 = line.strip().split(",")
                data = {
                    "name": name,
                    "quiz_1": int(quiz_1),
                    "quiz_2": int(quiz_2),
                    "quiz_3": int(quiz_3)
                }
                records.append(data)

if __name__ == "__main__":
    main()