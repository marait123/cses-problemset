#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
#define MAX_N 100000

void count_comb(int n, int sum, int &ways)
{
    if (sum == n)
    {
        ways++;
    }
    else if (sum > n)
    {
        return;
    }
    else
    {
        for (int i = 1; i <= 6; i++)
        {
            count_comb(n, sum + i, ways);
        }
    }
}

int count_comb2(int n, vector<int> &memory)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n < 0)
    {
        return 0;
    }

    if (memory[n] != -1)
    {
        return memory[n];
    }

    int ways = 0;

    for (int i = 1; i <= 6; i++)
    {
        ways += count_comb2(n - i, memory);
    }
    memory[n] = ways;
    return ways;
}

int main()
{
    // freopen("case1.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> memory(MAX_N, -1);
    int num_of_ways = count_comb2(n, memory);
    cout << num_of_ways << endl;
    return 0;
}