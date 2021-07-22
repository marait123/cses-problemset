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
    int N = -1;
    // freopen("case1.txt", "r", stdin);
    cin >> N;
    vector<int> vec(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }
    return 0;
}