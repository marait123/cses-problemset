// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <set>
#include <unordered_set>
#include <map>
using namespace std;
#define MAX_N 100000
#define REP(u, m) for (auto u : m)
void algo3(vector<int> a, vector<int> b)
{
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    int a_i = 0, b_i = 0;
    while (a_i < a.size() && b_i < b.size())
    {
        if (a[a_i] == b[b_i])
        {
            cout << a[a_i] << endl;

            a_i++;
            b_i++;
        }
        else if (a[a_i] > b[b_i])
        {

            // cout << a[a_i] << endl;
            a_i++;
        }
        else
        {
            // cout << b[b_i] << endl;
            b_i++;
        }
    }

    while (a_i < a.size())
    {
        // cout << a[a_i] << endl;
        a_i++;
    }

    while (b_i < b.size())
    {
        // cout << b[b_i] << endl;
        b_i++;
    }
}

void algo2(vector<int> a, vector<int> b)
{
    // use set
    set<int> s;
    for (int i = 0; i < b.size(); i++)
    {
        s.insert(b[i]);
    }

    for (auto u : a)
    {
        if (s.find(u) != s.end())
        {
            cout << u << endl;
        }
    }
}
int main()
{
    vector<int> A = {5, 2, 8, 9, 4}, B = {3, 2, 9, 5};
    algo2(A, B);
    // find those not in both
}