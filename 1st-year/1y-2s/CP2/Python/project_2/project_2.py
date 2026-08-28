import json
import os
import random

class Manager:
    def __init__(self):
        self.record = []
        self.num = 5

    def register(self, name, password):
        if self.is_duplicate(name):
            print("Name already exists")
            return

        data = {
            "name" : name,
            "password" : password,
            "per_score" : [0,0,0,0],
            "total_win" : 0
        }

        self.record.append(data)
        self.record.sort(key = lambda data : data["name"], reverse = True)

        print("Successfully registered!")
        os.system("pause")
        return

    def is_duplicate(self, name):
        for data in self.record:
            if name == data["name"]:
                return True
        return False
     
    def save(self):
        with open("game_record.json", "w") as file:
            json.dump(self.record, file, indent = 4)

    def load(self):
        if os.path.exists("game_record.json"):
            with open("game_record.json", "r") as file:
                self.record = json.load(file)
                self.record.sort(key = lambda data : data["total_win"], reverse = True)

    def login(self, name, password):
        if not self.record:
            print("No users registered yet.")
        
        found = False
        for data in self.record:
            if data["name"] == name:
                found = True
                if data["password"] == password:
                    return self.game_menu(data)
                else:
                    print("Wrong password")
                    break

        if found == False:
            print("User not found")

        os.system("pause")
        return
    
    def leaderboard_menu(self):
        while True:
            os.system("cls")
            print("Leaderboard Menu")
            print("[1] Addition")
            print("[2] Subtraction")
            print("[3] Multiplication")
            print("[4] Division")
            print("[5] Overall")
            print("[6] Return to Game Menu")
            try:
                choice = int(input("Select [1-6] only: "))
            except ValueError:
                print("Invalid Input")
                continue

            result = self.leaderboard(choice)
            if result == True:
                break
            
    def leaderboard(self, choice):
        os.system("cls")
        
        titles = ["Addition", "Subtraction", "Multiplication", "Division", "Overall"]

        match choice:
            case 1 | 2 | 3 | 4:
                self.record.sort(key = lambda data : data["per_score"][choice - 1], reverse = True)

            case 5:
                self.record.sort(key = lambda data : data["total_win"], reverse = True)

            case 6:
                print("Returning to Game Menu...")
                os.system("pause")
                return True

            case _:
                print("Invalid Input")
                os.system("pause")
                return False
            
        print(f"{titles[choice - 1]} Leaderboards")
        print("{:<10} {:<5} {:<5}".format("NAME", ":", "SCORE"))
        idx = 0
        for data in self.record:
            score = (data["per_score"][choice - 1] if choice <= 4 else data["total_win"])
            print("{:<10} {:<5} {:<5}".format(data["name"], ":", score))
            idx += 1
            if idx == 10:
                break

        os.system("pause")
        return False

    def main_menu(self):
        os.system("cls")

        print("Main Menu")
        print("-"*32)
        print("[1] Register")
        print("[2] Login")
        print("[3] Exit")
        try:
            choice = int(input("Select [1-3] only: "))
        except ValueError:
            return

        return choice

    def game_menu(self, player):
        g = Game(player, self)
        while True:
            os.system("cls")
            print("Game Menu")
            print("-"*32)
            print(f"Username: {player['name']}")
            print("-"*32)
            print("[1] Addition")
            print("[2] Subtraction")
            print("[3] Multiplication")
            print("[4] Division")
            print("[5] Leaderboards")
            print("[6] Logout")
            try:
                choice = int(input("Select [1-6] only: "))
            except ValueError:
                print("Invalid Input")
                continue
            os.system("cls")
            match choice:
                case 1 | 2 | 3 | 4:
                    print("You are given an equation, try to solve it correctly!")
                    print("-"*32)
                    g.game(self.num, choice)
                case 5:
                    self.leaderboard_menu()
                case 6:
                    print("Logging out...")
                    self.save()
                    os.system("pause")
                    break
                case _:
                    print("Invalid input")
                    os.system("pause")
                    continue


class Game:

    def __init__(self, player, manager):
        self.player = player
        self.manager = manager

    def game(self, number, mode, count = 0):
        operator = ["+", "-", "*", "/"]
        total = number
        while number != 0:
            number -= 1

            num1 = random.randint(1,20)
            num2 = random.randint(1,20)

            match mode:
                case 1:
                    correct = num1 + num2
                case 2:
                    if num1 < num2:
                        temp = num1
                        num1 = num2
                        num2 = temp
                    correct = num1 - num2
                case 3:
                    correct = num1 * num2
                case 4: 
                    while num1 % num2 != 0:
                        num2 = random.randint(1,20)
                    correct = num1 // num2
            try:
                answer = int(input(f"What is {num1} {operator[mode - 1]} {num2}: "))
            except ValueError:
                print("Invalid Input")
                continue

            if answer == correct:
                print(f"Correct Answer!")
                count += 1
            else:
                print(f"The correct answer is {correct}")
            
            print("-"*32)
            print(f"{self.player['name']}'s score is {count} / {total}")
            print("-"*32)

            if count == total:
                print("You win!")
                self.player["per_score"][mode - 1] += 1
                self.player["total_win"] += 1
                break
        
        if count != total:
            print("You lost...")
        
        os.system("pause")
        self.manager.leaderboard(mode)
        return

def main():    
    manager = Manager()

    manager.load()
    
    while True:
        match(manager.main_menu()):
            case 1:
                name = input("What's your name: ")
                password = input("Input your password: ")
                manager.register(name, password)
            case 2:
                name = input("What's your name: ")
                password = input("Input your password: ")
                manager.login(name, password)
            case 3:
                print("Exiting...")
                manager.save()
                break
            case _:
                print("Invalid input")
                os.system("pause")

main()

