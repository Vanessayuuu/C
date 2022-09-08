#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Go through each row
    for (int i = 0; i < height; i++)
    {
        //Go through each column
        for (int j = 0; j < width; j++)
        {
            //Convert pixels to float
            float Red = image[i][j].rgbtRed;
            float Green = image[i][j].rgbtGreen;
            float Blue = image[i][j].rgbtBlue;

            //Calculate the average value
            int average = round((Red + Green + Blue) / 3);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Go through each row
    for (int i = 0; i < height; i++)
    {
        //Go through each column
        for (int j = 0; j < width / 2; j++)
        {
            //Swap pixels within the same row
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Create a copy of the image
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0 ; j < width; j++)
        {
            int totalRed, totalGreen, totalBlue;
            totalRed = totalGreen = totalBlue = 0;
            float count = 0.00;

            //Get neibouring pixels
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    //Check if the neibouring pixel is valid
                    if (currentX < 0 || currentX > (width - 1) || currentY < 0 || currentY > (height - 1))
                    {
                        continue;
                    }

                    //Get image value
                    totalRed += image[currentX][currentY].rgbtRed;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    totalBlue += image[currentX][currentY].rgbtBlue;

                    count++;
                }
            }

            //Calculate the average of neibouring pixels
            temp[i][j].rgbtRed = round(totalRed / count);
            temp[i][j].rgbtGreen = round(totalGreen / count);
            temp[i][j].rgbtBlue = round(totalBlue / count);

        }
    }

    //Copy the new pixels into the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //Create a copy of the image
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    //Go through each row
    for (int i = 0; i < height; i++)
    {
        //Go through each column
        for (int j = 0; j < width; j++)
        {
            int redX = 0;
            int greenX = 0;
            int blueX = 0;
            int redY = 0;
            int greenY = 0;
            int blueY = 0;

            //Get neibouring pixels
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    //Check if the neibouring pixel is valid
                    if ((i - 1 + x < 0) || (i - 1 + x > width - 1) || (j - 1 + y < 0) || (j - 1 + y > height - 1))
                    {
                        continue;
                    }

                    //Calculate Gx for each colour
                    redX += (image[i - 1 + x][j - 1 + y].rgbtRed * Gx[x][y]);
                    greenX += (image[i - 1 + x][j - 1 + y].rgbtGreen * Gx[x][y]);
                    blueX += (image[i - 1 + x][j - 1 + y].rgbtBlue * Gx[x][y]);

                    //Calculate Gy for each colour
                    redY += (image[i - 1 + x][j - 1 + y].rgbtRed * Gy[x][y]);
                    greenY += (image[i - 1 + x][j - 1 + y].rgbtGreen * Gy[x][y]);
                    blueY += (image[i - 1 + x][j - 1 + y].rgbtBlue * Gy[x][y]);
                }
            }

            //Calculate the square root of (Gx^2 + Gy^2)
            int red = round(sqrt(redX * redX + redY * redY));
            int green = round(sqrt(greenX * greenX + greenY * greenY));
            int blue = round(sqrt(blueX * blueX + blueY * blueY));

            //Cap value at 255 for each colour if exceeds
            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }

            //Copy value into temp image
            temp[i][j].rgbtRed = red;
            temp[i][j].rgbtGreen = green;
            temp[i][j].rgbtBlue = blue;
        }
    }

    //Copy new pixels into original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
