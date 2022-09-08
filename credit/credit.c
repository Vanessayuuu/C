#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card_number;
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number < 0);

    int card2, card4, card6, card8, card10, card12, card14, card16, sum1;
    card2 = card_number % 100 / 10 * 2;
    card4 = card_number % 10000 / 1000 * 2;
    card6 = card_number % 1000000 / 100000 * 2;
    card8 = card_number % 100000000 / 10000000 * 2;
    card10 = card_number % 10000000000 / 1000000000 * 2;
    card12 = card_number % 1000000000000 / 100000000000 * 2;
    card14 = card_number % 100000000000000 / 10000000000000 * 2;
    card16 = card_number % 10000000000000000 / 1000000000000000 * 2;

    card2 = card2 / 10 + card2 % 10;
    card4 = card4 / 10 + card4 % 10;
    card6 = card6 / 10 + card6 % 10;
    card8 = card8 / 10 + card8 % 10;
    card10 = card10 / 10 + card10 % 10;
    card12 = card12 / 10 + card12 % 10;
    card14 = card14 / 10 + card14 % 10;
    card16 = card16 / 10 + card16 % 10;

    sum1 = card2 + card4 + card6 + card8 + card10 + card12 + card14 + card16;

    int card1, card3, card5, card7, card9, card11, card13, card15, sum2;

    card1 = card_number % 10;
    card3 = card_number % 1000 / 100;
    card5 = card_number % 100000 / 10000;
    card7 = card_number % 10000000 / 1000000;
    card9 = card_number % 1000000000 / 100000000;
    card11 = card_number % 100000000000 / 10000000000;
    card13 = card_number % 10000000000000 / 1000000000000;
    card15 = card_number % 1000000000000000 / 100000000000000;

    sum2 = card1 + card3 + card5 + card7 + card9 + card11 + card13 + card15;

    int sum3;

    sum3 = sum1 + sum2;

    //Validating credit card numbers
    if (sum3 % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    //Differentiate between VISA, MASTERCARD and AMEX
    int count;
    long card_count = card_number;
    long visa = card_number;
    long mastercard = card_number;
    long amex = card_number;

    for (count = 0; card_count > 0; count++)
    {
        card_count /= 10;
    }

    //Check if it is VISA
    do
    {
        visa /= 10;
    }
    while (visa >= 10);

    if ((count == 13 || count == 16) && visa == 4)
    {
        printf("VISA\n");
        return 0;
    }

    //Check if it is MASTERCARD
    while (mastercard > 100000000000000)
    {
        mastercard /= 100000000000000;
    }

    if (count == 16 && (mastercard == 51 || mastercard == 52 || mastercard == 53 || mastercard == 54 || mastercard == 55))
    {
        printf("MASTERCARD\n");
        return 0;
    }

    //Check if it is AMEX
    while (amex > 100000000000000)
    {
        amex /= 10000000000000;
    }

    if (count == 15 && (amex == 34 || amex == 37))
    {
        printf("AMEX\n");
        return 0;
    }

    //When the card is neither VISA, MASTERCARD nor AMEX
    else
    {
        printf("INVALID\n");
        return 0;
    }

}
