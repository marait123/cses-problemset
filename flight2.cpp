#include <bits/stdc++.h>

#define int long long
using namespace std;

int const MAXN = 100;
int n, k, T, input_array[MAXN], A, B;
int memory[MAXN][MAXN];

// uses the memorey
// where in the column num is stored
//  and in the rows the current number of boxes
int recursively_solve(int x)
{
    int res = 0, num = k;
    for (int i = 1; i <= n; ++i)
    {
        if (x < input_array[i])
            continue;
        res += memory[n - i][num];
        if (!num)
            return res;
        x -= input_array[i], num--;
    }
    return res + (num == 0);
}

signed main()
{
    // freopen("case1.txt", "r", stdin);

    for (int i = 0; i < MAXN; ++i)
        for (int j = 0; j <= i; ++j)
            if (j == 0)
                memory[i][j] = 1;
            else
                memory[i][j] = (memory[i - 1][j] + memory[i - 1][j - 1]);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> input_array[i];
    // firstly sort the input weight in increasing order
    sort(input_array + 1, input_array + n + 1, greater<int>());
    cin >> A >> B;

    // this is the number of elements that are (those less than b - those less than a)
    int result = recursively_solve(B) - recursively_solve(A - 1);
    cout << result;
    return 0;
}