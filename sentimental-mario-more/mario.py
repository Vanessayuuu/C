# TODO
from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height >= 1 and height <= 8:
        break
for row in range(height):
    for space in range(height - row - 1):
        print(" ", end="")
    # Count 0 is the left pyrimid and count 1 is the right pyrimid
    for count in range(2):
        for brick in range(row + 1):
            print("#", end="")
        if count == 1:
            break
        print("  ", end="")
    print()