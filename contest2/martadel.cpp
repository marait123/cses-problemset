
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
    ll T, r1, r2;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> r1 >> r2;
        if (r1 * r1 > ((r2 * r2) * 2))
        {
            cout << 1;
        }
        else
        {
            cout << 2;
        }
        cout << endl;
    }

    return 0;
}