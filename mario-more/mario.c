#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Enter the height of pyrimids (1-8): ");
    }
    while (height > 8 || height < 1);

    for (int row = 0; row < height; row++)
    {
        for (int space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }
        //build bricks in left and right pyrimids
        for (int count = 0; count < 2; count++) //count 0: left pyrimid; count 1: right pyrimid
        {
            for (int brick = 0; brick <= row; brick++)
            {
                printf("#");
            }
            if (count == 1) break;
            printf("  ");
        }
        printf("\n");
    }
}