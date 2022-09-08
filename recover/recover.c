#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //Check the command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    //Open file for reading
    FILE *input_file = fopen(argv[1], "r");

    //Check that the input_file is valid
    if (input_file == NULL)
    {
        printf("Could not open file\n");
        return 2;
    }

    unsigned char buffer[512];
    int image_count = 0;

    FILE *output_file = NULL;
    char *filename = malloc(8 * sizeof(char));

    //Read the blocks of 512 bytes
    while (fread(buffer, sizeof(char), 512, input_file) == 512)
    {
        //Detect the start of JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //Create the JPEG filename
            sprintf(filename, "%03i.jpg", image_count);

            //Open output file for writing
            output_file = fopen(filename, "w");

            //Count number of images
            image_count++;
        }

        //Check if the output file has been used
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }
    free(filename);
    fclose(input_file);
    fclose(output_file);

    return 0;

}