# TODO
from cs50 import get_int
from sys import exit

# Validate the card number
while True:
    card_number = get_int("Number: ")
    if card_number > 0:
        break

card2 = card_number % 100 // 10 * 2
card4 = card_number % 10000 // 1000 * 2
card6 = card_number % 1000000 // 100000 * 2
card8 = card_number % 100000000 // 10000000 * 2
card10 = card_number % 10000000000 // 1000000000 * 2
card12 = card_number % 1000000000000 // 100000000000 * 2
card14 = card_number % 100000000000000 // 10000000000000 * 2
card16 = card_number % 10000000000000000 // 1000000000000000 * 2

card2 = card2 // 10 + card2 % 10
card4 = card4 // 10 + card4 % 10
card6 = card6 // 10 + card6 % 10
card8 = card8 // 10 + card8 % 10
card10 = card10 // 10 + card10 % 10
card12 = card12 // 10 + card12 % 10
card14 = card14 // 10 + card14 % 10
card16 = card16 // 10 + card16 % 10

sum1 = card2 + card4 + card6 + card8 + card10 + card12 + card14 + card16

card1 = card_number % 10
card3 = card_number % 1000 // 100
card5 = card_number % 100000 // 10000
card7 = card_number % 10000000 // 1000000
card9 = card_number % 1000000000 // 100000000
card11 = card_number % 100000000000 // 10000000000
card13 = card_number % 10000000000000 // 1000000000000
card15 = card_number % 1000000000000000 // 100000000000000

sum2 = card1 + card3 + card5 + card7 + card9 + card11 + card13 + card15

sum3 = sum1 + sum2

if sum3 % 10 != 0:
    print("INVALID")
    exit()

# Check if it is VISA, MASTERCARD or AMEX
visa = card_number
master = card_number
amex = card_number
card_count = card_number
count = 0

# Count the number of digits of the card number
while card_count > 0:
    card_count //= 10
    count += 1

# Check for VISA
while visa >= 10:
    visa //= 10

if visa == 4 and (count == 13 or count == 16):
    print("VISA")
    exit()

# Check for MASTERCARD
check_master = master // 100000000000000
if (check_master >= 51 and check_master <= 55) and count == 16:
    print("MASTERCARD")
    exit()

# Check for AMEX
check_amex = amex // 10000000000000
if (check_amex == 34 or check_amex == 37) and count == 15:
    print("AMEX")
    exit()