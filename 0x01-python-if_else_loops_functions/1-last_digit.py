#!/usr/bin/python3
import random
number = random.randint(-10000, 10000)
string = str(number)
last_d = int(string[-1])
for num in string:
    if num == "-":
        last_d *= -1
        continue
    else:
        if last_d > 5:
            print(f"Last digit of {number} is {last_d} and is greater than 5")
        elif last_d  < 6 and num != 0:
            print(f"Last digit of {number} is {last_d} and is less than 6 and not 0")
        else:
            print(f"Last digit of {number} is {last_d} and is 0")
        break
