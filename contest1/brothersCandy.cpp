
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
int sum(vector<ll> &vec)
{
    ll res = 0;
    for (size_t i = 0; i < vec.size(); i++)
    {
        res += vec[i];
    }
    return res;
}
int main()
{

    vector<ll> k = {2, 2, 5, 3};
    ll n = k.size();

    for (int mask = 0; mask < (1 << n); mask++)
    {
        vector<ll> coin_comb;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                // cout << s[i];
                coin_comb.push_back(k[i]);
            }
        }

        if (sum(coin_comb) >= S && coin_comb.size() > max_comb_length)
        {
            // if removing an element causes no change in condition sum(coin_comb) <= S
            // if not then max_comb_length = coin_comb.size()
            bool found_counter = false;
            for (size_t i = 0; i < coin_comb.size(); i++)
            {
                if (sum(coin_comb) - coin_comb[i] >= S)
                {
                    found_counter = true;
                }
            }
            if (!found_counter)
            {
                max_comb_length = coin_comb.size();
            }
        }
    }

    cout << max_comb_length << endl;

    return 0;
}