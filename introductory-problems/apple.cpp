#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
#define MAX_N 100000
#define ll long long
void MinDiff(vector<bool> chosen, int sum, ll total_sum, vector<int> &prices, ll &minDiff)
{
    if (true)
    {
    }
    else
    {

        for (size_t i = 0; i < chosen.size(); i++)
        {
            if (chosen[i] == false)
            {
                chosen[i] = true;
                MinDiff(chosen, sum + prices[i], total_sum, prices, minDiff);
                chosen[i] = false;
            }
        }
    }
}
int main()
{
    // freopen("case1.txt", "r", stdin);
    int N = -1;
    cin >> N;
    vector<int> vec(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
    }

    ll total_sum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        total_sum += vec[i];
    }
    ll min_diff = INT64_MAX / 2;
    for (int i = 0; i < (1 << N); i++)
    {
        ll g1 = 0;
        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j))
            {
                g1 += vec[j];
            }
        }
        ll g2 = total_sum - g1;
        if (abs(g1 - g2) < min_diff)
        {
            min_diff = abs(g1 - g2);
        }
    }
    cout << min_diff << endl;
    return 0;
}