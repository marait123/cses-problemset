

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <queue>
#include <map>
#include <stack>
using namespace std;
#define MAX_N 100000
#define ll long long
#define OO INT32_MAX

bool is_safe(vector<vector<char>> &grid, int row, int col)
{

    int n = grid.size();
    // try same column
    for (size_t i = 0; i < n; i++)
    {
        if (grid[i][col] == 'q')
        {
            return false;
        }
    }
    // try same row
    for (size_t i = 0; i < n; i++)
    {
        if (grid[row][i] == 'q')
        {
            return false;
        }
    }

    int i, j;
    //try the main diagonal
    i = row, j = col;
    while (i > 0 && j > 0)
    {
        i--;
        j--;
        if (grid[i][j] == 'q')
        {
            return false;
        }
    }
    i = row, j = col;
    while (i < n - 1 && j < n - 1)
    {
        i++;
        j++;
        if (grid[i][j] == 'q')
        {
            return false;
        }
    }

    //try the secondary diagonal
    i = row, j = col;
    while (i < n - 1 && j > 0)
    {
        i++;
        j--;
        if (grid[i][j] == 'q')
        {
            return false;
        }
    }
    i = row, j = col;
    while (i > 0 && j < n - 1)
    {
        i--;
        j++;
        if (grid[i][j] == 'q')
        {
            return false;
        }
    }

    return true;
}
int ways = 0;
void queens(int row, vector<vector<char>> grid, int n)
{
    if (row == n)
    {
        ways++;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (grid[row][i] == '.' && is_safe(grid, row, i))
            {
                grid[row][i] = 'q';
                queens(row + 1, grid, n);
                grid[row][i] = '.';
            }
            else
            {
                continue;
            }
        }
    }
}
int main()
{
    // freopen("case1.txt", "r", stdin);
    int n = 8;
    vector<vector<char>> grid(n, vector<char>(n, '.'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    queens(0, grid, n);
    cout << ways << endl;
    return 0;
}

// ........
// ........
// ..*.....
// ........
// ........
// .....**.
// ...*....
// ........