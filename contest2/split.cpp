
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <queue>
#include <map>
#include <stack>
#include <math.h>
using namespace std;
#define MAX_N 100000
#define ll long long
#define OO INT32_MAX

int main()
{
    // freopen("case1.txt", "r", stdin);
    int T, x, n;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> x >> n;
        if (x < n)
        {
            cout << -1 << endl;
            continue;
        }
        int temp_div = x / n;
        vector<int> nums(n, 0);

        for (int i = 0; i < n; i++)
        {
            nums[i] = temp_div;
        }
        int rest = x - temp_div * n;
        for (int i = 0; i < rest; i++)
        {
            nums[n - i - 1] += 1;
        }

        for (int i = 0; i < n; i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }

    return 0;
}