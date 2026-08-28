import json
import os

def get_highest(scores, i = 0):
    if i == len(scores) - 1:
        return scores[i]

    temp = get_highest(scores, i+1)   
    if scores[i] > temp:
        return scores[i]
    
    return temp

def sum_scores(scores, i = 0):
    if i == len(scores) - 1:
        return scores[i]
    
    return scores[i] + sum_scores(scores, i+1)

def factorial(num):
    if num <= 1:
        return 1
    
    return num * factorial(num - 1)

class Player:
    def __init__(self, name, password, scores, total_wins, highest_score):
        self.name = name
        self.password = password
        self.scores = scores
        self.total_wins = int(total_wins)
        self.highest_score = int(highest_score)

class GameManager:
    def __init__(self):
        self.MAX = 10
        self.record = []

    def register(self, name, password):
        if self.is_full():
            print("Lobby is full")
            os.system("pause")
            return
        elif self.locate(name) != -1:
            print("Player already exists")
            os.system("pause")
            return
        else:
            self.record.append(Player(name, password, [], 0, 0))
            self.save()
            print("Registered Successfully")
            os.system("pause")
    
    def login(self, name, password):
        index = self.locate(name)

        if index == -1:
            print("Player not found")
            os.system("pause")
            return

        if password == self.record[index].password:
            return self.record[index]
        
        print("Wrong Password")
        os.system("pause")
        return None
    
    def save(self):
        with open("records.json", "w") as file:
            data_list = []
            for player in self.record:
                data = {
                    "name" : player.name,
                    "password" : player.password,
                    "scores" : player.scores,
                    "total_wins" : player.total_wins,
                    "highest_score" : player.highest_score
                }
                data_list.append(data)
            json.dump(data_list, file, indent = 4)
    
    def load(self):
        if os.path.exists("records.json"):
            with open("records.json", "r") as file:
                self.record = json.load(file)
                for i, data in enumerate(self.record):
                    self.record[i] = Player(data["name"], 
                    data["password"], 
                    data["scores"], 
                    data["total_wins"], 
                    data["highest_score"])
    
    def display_leaderboard(self):
        pass
    
    def locate(self, name):
        for i, data in enumerate(self.record):
            if data.name == name:
                return i
            
        return -1
                
    def is_empty(self):
        return len(self.record) == 0

    def is_full(self):
        return len(self.record) == self.MAX