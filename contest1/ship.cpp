
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <queue>
using namespace std;
#include <map>
#include <stack>
#define MAX_N 100000
#define ll long long
#define OO INT32_MAX

int main()
{
    // freopen("case1.txt", "r", stdin);
    vector<vector<bool>> grid(10, vector<bool>(10, false));
    int N;
    cin >> N;

    bool violation = false;
    for (size_t i = 0; i < N; i++)
    {
        int D, L, R, C;
        cin >> D >> L >> R >> C;
        R--;
        C--;
        if (D == 0) // horizonatally
        {
            for (int i = C; i < C + L; i++)
            {
                if (R >= 10 || i >= 10 || grid[R][i])
                {
                    violation = true;
                    cout << "N";
                    return 0;
                }
                else
                {
                    grid[R][i] = true;
                }
            }
        }
        else //vertically
        {
            for (int i = R; i < R + L; i++)
            {
                if (i >= 10 || C >= 10 || grid[i][C])
                {
                    violation = true;
                    cout << "N";
                    return 0;
                }
                else
                {
                    grid[i][C] = true;
                }
            }
        }
    }

    if (!violation)
    {
        cout << "Y" << endl;
    }
    else
    {
        cout << "N" << endl;
    }

    return 0;
}