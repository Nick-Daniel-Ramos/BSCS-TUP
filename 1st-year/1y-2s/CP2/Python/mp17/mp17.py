import os
import json

class Manager:
    def __init__(self):
        self.max = 5
        self.record = []

    def addR(self, name, q_1, q_2, q_3):
        if len(self.record) == self.max:
            print("Record is full")
            os.system("pause")
        else:a
                
            data = {
                "name" : name,
                "quiz_1" : q_1,
                "quiz_2" : q_2,
                "quiz_3" : q_3,                        
            }

            self.record.append(data)
            self.record.sort(key = lambda data : data["name"])

    def delR(self, name):
        if not self.record:
            print("Empty Records")
            os.system("pause")
            return

        for data in self.record:
            if data["name"].lower() == name.lower():
                self.record.remove(data)
                print(f"{name} successfully deleted.")
                os.system("pause")
                return

        print(f"{name} not found")
        os.system("pause")

    def update(self, name):
        if not self.record:
            print("Empty Records")
            os.system("pause")
            return
        
        for data in self.record:
            if data["name"].lower() == name.lower():
                while True:
                    os.system("cls")

                    ave = self.average(data["quiz_1"], data["quiz_2"], data["quiz_3"])

                    print("UPDATE MENU")
                    print("-"*32)
                    print(f"Record of {data["name"]}")
                    print("-"*32)
                    print(f"Quiz 1: {data["quiz_1"]:<10}")
                    print(f"Quiz 2: {data["quiz_2"]:<10}")
                    print(f"Quiz 3: {data["quiz_3"]:<10}")
                    print(f"AVERAGE: {ave:<10.2f}")

                    print("UPDATE OPTIONS")
                    print("[1] Update Quiz 1")
                    print("[2] Update Quiz 2")
                    print("[3] Update Quiz 3")
                    print("[4] Return to Menu")
                    choice = int(input("Enter your choice: "))

                    match choice:

                        case 1:
                            data["quiz_1"] = int(input("Enter new score on quiz 1: "))
                        case 2:
                            data["quiz_2"] = int(input("Enter new score on quiz 2: "))
                        case 3:
                            data["quiz_3"] = int(input("Enter new score on quiz 3: "))
                        case 4:
                            break
                        case _:
                            print("Invalid input, [1-4] only")
                            os.system("pause")
                    os.system("cls")
                print("successfully updated")
        os.system("pause")

    def save(self):
        with open("record.json", "w") as file:
            json.dump(self.record, file, indent = 4)

    def load(self):
        if os.path.exists("record.json"):
            with open("record.json", "r") as file:
                self.record = json.load(file)        


    def display(self):
        os.system("cls")
        print(f"{'NO.':<10}{'NAME':<20}{'QUIZ 1':<10}{'QUIZ 2':<10}{'QUIZ 3':<10}{'AVERAGE':<10}{'REMARKS':<10}")

        for data in enumerate(self.record):
            i = 0
            ave = self.average(data["quiz_1"], data["quiz_2"], data["quiz_3"])
            print(f"{i+1:<10}{data["name"]:<20}"
                f"{data["quiz_1"]:<10}"
                f"{data["quiz_2"]:<10}"
                f"{data["quiz_3"]:<10}"
                f"{ave:<10.2f}"
                f"{"PASSED" if ave >= 75 else "FAILED":<10}")
        
        os.system("pause")

    def is_duplicate(self, name):
        data_name = {daa["name"].lower() for data in selft.record}

        if name.lower() in data_name:
            return True

        return False

    def average(self, q_1, q_2, q_3):
        return float((q_1 + q_2 + q_3) / 3)

def main():
    Record = Manager()

    Record.load()

    def menu():
        os.system("cls")
        print("MENU")
        print("-"*32)
        print("[1] Add Record")
        print("[2] Delete Record")        
        print("[3] Update Record")
        print("[4] Display Record")
        print("[5] Exit")
        choice = int(input("Select [1-4] only: "))
        return choice

    while True:
        match(menu()):
            case 1:
                name = input("Enter name: ")
                if Record.is_duplicate(name):
                    print(f"{name} already in record")
                    os.system("pause")
                else:
                    q_1 = int(input("Enter Quiz 1: "))
                    q_2 = int(input("Enter Quiz 2: "))
                    q_3 = int(input("Enter Quiz 3: "))
                    Record.addR(name, q_1, q_2, q_3)

            case 2:
                name = input("Enter name: ")
                Record.delR(name)
            
            case 3:
                name = input("Enter name: ")
                Record.update(name)
            
            case 4:
                Record.display()
            
            case 5:
                print("Exiting...")
                Record.save()
                break
            
            case _:
                print("Invalid input, [1-4] only")
                os.system("pause")


if __name__ == "__main__":
    main()
