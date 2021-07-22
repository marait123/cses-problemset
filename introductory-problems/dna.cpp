#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
#define MAX_N 100000
#define LL long long
void solve_recur(LL n)
{
    if (n == 1)
    {
        cout << n << endl;
        return;
    }
    else if (n % 2 == 0)
    {
        cout << n << " ";
        solve_recur(n / 2);
    }
    else
    {
        // it is odd
        cout << n << " ";
        solve_recur(n * 3 + 1);
    }
}
int main()
{
    // freopen("case1.txt", "r", stdin);
    string sequence;
    cin >> sequence;
    int n = sequence.size();
    int i = 1;
    char start = sequence[0];
    int max_count = 1;
    int curr_count = 1;
    while (i < n)
    {
        if (sequence[i] == start)
        {
            curr_count++;
            if (curr_count > max_count)
            {
                max_count = curr_count;
            }
        }
        else
        {
            curr_count = 1;
            start = sequence[i];
        }
        i++;
    }
    cout << max_count << endl;
    return 0;
}