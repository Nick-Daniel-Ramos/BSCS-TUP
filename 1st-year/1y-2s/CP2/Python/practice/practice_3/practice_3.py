import random

row = 3
col = 3

maze = []

for i in range(row):
    rows = []
    for j in range(col):
        rows.append(random.randint(1,100))
        if rows[j] < 30:
            rows[j] = 1
        else:
            rows[j] = 0 
    maze.append(rows)

print(maze)
