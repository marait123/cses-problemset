
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <queue>
#include <map>
#include <stack>
using namespace std;
#define MAX_N 100000
#define ll long long
#define OO INT32_MAX
void gen_subsets(int k, vector<int> subset, int n, vector<vector<int>> &subsets)
{
    if (k == n)
    {
        subsets.push_back(subset);
    }
    else
    {
        gen_subsets(k + 1, subset, n, subsets);
        subset.push_back(k);
        gen_subsets(k + 1, subset, n, subsets);
    }
}

void permute(vector<bool> chosen, vector<int> subset, int n, vector<vector<int>> &subsets)
{
    if (subset.size() == n)
    {
        subsets.push_back(subset);
    }
    else
    {

        for (int i = 0; i < n; i++)
        {
            if (!chosen[i])
            {
                chosen[i] = true;
                subset.push_back(i);
                permute(chosen, subset, n, subsets);
                chosen[i] = false;
                subset.pop_back();
            }
        }
    }
}
int main()
{
    freopen("case1.txt", "r", stdin);
    vector<vector<int>> subsets;
    int n = 5;
    vector<bool> chosen(n, false);
    permute(chosen, vector<int>(), n, subsets);
    for (auto subset : subsets)
    {
        for (auto el : subset)
        {
            cout << el << " ,";
        }
        cout << endl;
    }
    return 0;
}