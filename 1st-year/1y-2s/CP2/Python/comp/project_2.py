import json
import os
import random

QUESTIONS_PER_MATCH = 5
MAX_PLAYERS = 128
OPERATION_NAMES = ["Addition", "Subtraction", "Multiplication", "Division"]
OPERATION_SYMBOLS = ["+", "-", "*", "/"]
DATA_FILE = "records.json"


class Player:
    def __init__(self, name, password, operation=None, total_wins=0):
        self.name = name
        self.password = password
        self.operation = operation if operation is not None else [0, 0, 0, 0]
        self.total_wins = total_wins


class PlayerManager:

    def __init__(self):
        self.MAX = MAX_PLAYERS
        self.players = []

    def load_records(self):
        if not os.path.exists(DATA_FILE):
            return
        with open(DATA_FILE) as f:
            for d in json.load(f):
                self.players.append(Player(
                    d["name"], d["password"],
                    d.get("operation", [0, 0, 0, 0]),
                    d.get("total_wins", 0)
                ))

    def save_records(self):
        with open(DATA_FILE, "w") as f:
            json.dump([{
                "name": p.name,
                "password": p.password,
                "operation": p.operation,
                "total_wins": p.total_wins
            } for p in self.players], f, indent=2)

    def locate(self, name):
        for i, player in enumerate(self.players):
            if player.name == name:
                return i
        return -1

    def is_empty(self):
        return len(self.players) == 0

    def is_full(self):
        return len(self.players) == self.MAX

    def register(self, name, password):
        if self.is_full():
            print("Player List is Full")
        elif self.locate(name) != -1:
            print("Player Already Exists")
        else:
            self.players.append(Player(name, password))
            self.save_records()
            print("Registered Successfully")
        os.system("pause")

    def login(self, name, password):
        pos = self.locate(name)
        if pos == -1:
            print("Username Not Found")
            os.system("pause")
            return -1
        if self.players[pos].password != password:
            print("Wrong Password")
            os.system("pause")
            return -1
        return pos

    def leaderboard(self, operation):
        os.system("cls")
        label = OPERATION_NAMES[operation] if operation < 4 else "Overall"
        ranked = sorted(
            self.players,
            key=lambda p: (-(p.operation[operation] if operation < 4 else p.total_wins), p.name)
        )
        print(f"TOP 10 — {label.upper()}")
        print("-" * 35)
        if self.is_empty():
            print("No Records Yet")
        else:
            for rank, p in enumerate(ranked[:10], 1):
                score = p.operation[operation] if operation < 4 else p.total_wins
                print(f"{rank:>2}. {p.name:<20} {score} wins")
        print()
        os.system("pause")

    def leaderboard_menu(self):
        while True:
            os.system("cls")
            print("LEADERBOARDS")
            print("[1] Addition")
            print("[2] Subtraction")
            print("[3] Multiplication")
            print("[4] Division")
            print("[5] Overall")
            print("[6] Back")
            choice = int(input("Enter your choice: "))

            match choice:
                case 1 | 2 | 3 | 4 | 5:
                    self.leaderboard(choice - 1)
                case 6:
                    break
                case _:
                    print("Invalid Input, [1-6] Only")
                    os.system("pause")

    def play_match(self, player_index, operation):
        player = self.players[player_index]
        score = 0

        os.system("cls")
        print(f"{player.name} — {OPERATION_NAMES[operation].upper()}")
        print(f"{QUESTIONS_PER_MATCH} Questions. Answer All Correctly to Earn a Point.")
        os.system("pause")

        for q in range(1, QUESTIONS_PER_MATCH + 1):
            os.system("cls")
            print(f"Q{q}/{QUESTIONS_PER_MATCH} | {player.name} | {OPERATION_NAMES[operation].upper()}")
            print(f"Score: {score}/{q - 1}")
            print()

            if operation == 0:
                a, b = random.randint(1, 20), random.randint(1, 20)
                correct = a + b
            elif operation == 1:
                a, b = random.randint(1, 20), random.randint(1, 20)
                a, b = max(a, b), min(a, b)
                correct = a - b
            elif operation == 2:
                a, b = random.randint(1, 10), random.randint(1, 10)
                correct = a * b
            else:
                a, b = 1, 2
                while a % b:
                    a, b = random.randint(1, 20), random.randint(1, 20)
                correct = a // b

            print(f"{a} {OPERATION_SYMBOLS[operation]} {b} = ", end="")
            try:
                if int(input().strip()) == correct:
                    print("Correct!")
                    score += 1
                else:
                    print(f"Wrong! The Answer Was {correct}.")
            except ValueError:
                print(f"Invalid Input. The Answer Was {correct}.")
            os.system("pause")

        os.system("cls")
        print("MATCH OVER")
        print(f"Player  : {player.name}")
        print(f"Score   : {score}/{QUESTIONS_PER_MATCH}")
        print()
        if score > QUESTIONS_PER_MATCH // 2:
            print("You Win!")
            self.players[player_index].operation[operation] += 1
            self.players[player_index].total_wins += 1
            self.save_records()
        else:
            print("Better Luck Next Time!")
        os.system("pause")


def main():
    manager = PlayerManager()
    manager.load_records()

    def auth_menu():
        os.system("cls")
        print("MATH GAME")
        print("[1] Login")
        print("[2] Register")
        print("[3] Exit")
        return int(input("Enter your choice: "))

    def game_menu(name):
        os.system("cls")
        print(f"GAME MENU ({name})")
        print("[1] Addition")
        print("[2] Subtraction")
        print("[3] Multiplication")
        print("[4] Division")
        print("[5] Leaderboards")
        print("[6] Logout")
        return int(input("Enter your choice: "))

    while True:
        match auth_menu():
            case 1:
                name = input("Enter Username: ")
                password = input("Enter Password: ")
                player_index = manager.login(name, password)
                if player_index != -1:
                    while True:
                        c = game_menu(name)
                        match c:
                            case 1 | 2 | 3 | 4:
                                manager.play_match(player_index, c - 1)
                            case 5:
                                manager.leaderboard_menu()
                            case 6:
                                break
                            case _:
                                print("Invalid Input, [1-6] Only")
                                os.system("pause")
            case 2:
                name = input("Enter Name: ")
                password = input("Enter Password: ")
                manager.register(name, password)
            case 3:
                print("Exiting...")
                manager.save_records()
                break
            case _:
                print("Invalid Input, [1-3] Only")
                os.system("pause")


if __name__ == "__main__":
    random.seed()
    main()