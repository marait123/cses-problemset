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
    long long N = -1;
    // freopen("case1.txt", "r", stdin);
    cin >> N;
    // N -= 1;
    vector<int> numVec(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> numVec[i];
    }

    sort(numVec.begin(), numVec.end());
    bool found = false;
    for (size_t i = 1; i < N; i++)
    {
        if (numVec[i] != numVec[i - 1] + 1)
        {
            found = true;
            cout << numVec[i] - 1 << endl;
            break;
        }
    }
    if (!found)
    {
        cout << N << endl;
    }
    return 0;
}