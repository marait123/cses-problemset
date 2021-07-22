
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

int main()
{
    // freopen("case1.txt", "r", stdin);
    int N;
    cin >> N;
    // vector<int> houses(N, 0);
    for (size_t i = 0; i < N; i++)
    {
        // houses[i] = (i) % 20 + 1;
        cout << (i) % 20 + 1 << " ";
        // cout << houses[i] << endl;
    }
    cout << endl;

    // swap index 19 with that before by 2
    // for (size_t i = 19; i < N; i+=20)
    // {
    //     int temp = houses[i];
    //     houses[i] = houses[i-2]
    // }

    return 0;
}