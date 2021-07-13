// https://codeforces.com/group/zvsr84He8w/contest/315331/problem/A
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <queue>

#include <map>
using namespace std;
#define MAX_N 100000
#define LL long long
#define OO INT32_MAX

int main()
{
    int N;
    cin >> N;
    vector<int> boxes(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> boxes[i];
    }

    sort(boxes.begin(), boxes.end());
    for (size_t i = 0; i < N; i++)
    {
        cout << boxes[i] << " ";
    }
    cout << endl;
    return 0;
}
