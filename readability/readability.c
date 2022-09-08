#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    //Prompt the user for text
    string text = get_string("Text: ");

    //Count the number of letters in the text
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
    }

    //Count the number of words in the text
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }

    //Count the number of sentences in the text
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    //Calculate the Coleman-Liau index and differentiate the reading level
    float L = (float)letters / (float)words * 100;
    float S = (float)sentences / (float)words * 100;
    float calculation = 0.0588 * L - 0.296 * S - 15.8;
    int index = round(calculation);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index <= 15)
    {
        printf("Grade %d\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}