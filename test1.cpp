// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
#define MAX_N 100000

int solution(int X, int Y, vector<int> &C)
{
    // write your code in C++14 (g++ 6.2.0)
    vector<vector<int>> matrix(X, vector<int>(X));
    for (int j = 0; j < X * X; j++)
    {
        matrix[j / X][j % X] = C[j];
    }
    int sum = 0;
    for (int row = 0; row < X; row++)
    {
        for (int col = 0; col < X; col++)
        {
            int pixel_sum = 0;
            int half = Y / 2;
            if (row == 0 || row == X - 1 || col == 0 || col == X - 1)
            {
                // then either corner or border
                if (row == 0 && col == 0)
                {
                    // top left corner
                    for (int row2 = row; row2 <= row + half; row2++)
                    {
                        for (int col2 = col; col2 <= col + half; col2++)
                        {
                            pixel_sum += matrix[row2][col2];
                        }
                    }
                    pixel_sum /= (ceil(Y * 1.0 / 2) * ceil(Y * 1.0 / 2));
                }
                else if (row == 0 && col == X - 1)
                {
                    // top right corner
                    for (int row2 = row; row2 <= row + half; row2++)
                    {
                        for (int col2 = col - half; col2 <= col; col2++)
                        {
                            pixel_sum += matrix[row2][col2];
                        }
                    }
                    pixel_sum /= (ceil(Y * 1.0 / 2) * ceil(Y * 1.0 / 2));
                }
                else if (row == X - 1 && col == X - 1)
                {
                    // bottom right corner
                    for (int row2 = row - half; row2 <= row; row2++)
                    {
                        for (int col2 = col - half; col2 <= col; col2++)
                        {
                            pixel_sum += matrix[row2][col2];
                        }
                    }
                    pixel_sum /= (ceil(Y * 1.0 / 2) * ceil(Y * 1.0 / 2));
                }
                else if (row == X - 1 && col == 0)
                {
                    // bottom left corner
                    for (int row2 = row - half; row2 <= row; row2++)
                    {
                        for (int col2 = col; col2 <= col + half; col2++)
                        {
                            pixel_sum += matrix[row2][col2];
                        }
                    }
                    pixel_sum /= (ceil(Y * 1.0 / 2) * ceil(Y * 1.0 / 2));
                }
                else
                {
                    // border pixel

                    // left
                    if (row == 0)
                    {
                        for (int row2 = row; row2 <= row + half; row2++)
                        {
                            for (int col2 = col - half; col2 <= col + half; col2++)
                            {
                                pixel_sum += matrix[row2][col2];
                            }
                        }
                        pixel_sum /= (Y * Y - Y * half);
                    }
                    else if (row == X - 1)
                    {
                        for (int row2 = row - half; row2 <= row; row2++)
                        {
                            for (int col2 = col - half; col2 <= col + half; col2++)
                            {
                                pixel_sum += matrix[row2][col2];
                            }
                        }
                        pixel_sum /= (Y * Y - Y * half);
                    }
                    else if (col == 0)
                    {
                        for (int row2 = row - half; row2 <= row + half; row2++)
                        {
                            for (int col2 = col; col2 <= col + half; col2++)
                            {
                                pixel_sum += matrix[row2][col2];
                            }
                        }
                        pixel_sum /= (Y * Y - Y * half);
                    }
                    else if (col == X - 1)
                    {
                        for (int row2 = row - half; row2 <= row + half; row2++)
                        {
                            for (int col2 = col - half; col2 <= col; col2++)
                            {
                                pixel_sum += matrix[row2][col2];
                            }
                        }
                        pixel_sum /= (Y * Y - Y * half);
                    }
                }
            }
            else
            {
                // normal pixel middle one
                for (int row2 = row - half; row2 <= row + half; row2++)
                {
                    for (int col2 = col - half; col2 <= col + half; col2++)
                    {
                        pixel_sum += matrix[row2][col2];
                    }
                }
                pixel_sum /= Y * Y;
            }
            cout << pixel_sum << endl;
            sum += pixel_sum;
        }
    }
    return sum;
}

int main()
{
    vector<int> v = {25, 43, 90, 102, 34, 52, 74, 86, 12, 182, 583, 439, 28, 202, 923, 11};
    solution(4, 4, v);
}