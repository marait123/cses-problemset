
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
    int T;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        vector<int> dict(1000, 0);
        for (size_t i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            dict[a - 1] += 1;
        }
        ll result = 1;
        for (size_t i = 0; i < 1000; i++)
        {
            if (dict[i] != 0)
            {

                // result *= dict[i];
                for (size_t j = dict[i]; j > 0; j--)
                {
                    result *= j;
                    result %= 7901;
                }
            }
        }
        cout << result << endl;
    }

    return 0;
}