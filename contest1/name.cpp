
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

int main()
{
    // freopen("case1.txt", "r", stdin);

    int N;
    cin >> N;

    vector<int> years(N);
    vector<int> ages(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> years[i] >> ages[i];
    }
    for (size_t i = 1; i < N; i++)
    {
        int age_dif = ages[i] - ages[i - 1];
        int year_dif = years[i] - years[i - 1];
        if (year_dif != age_dif)
        {
            cout << "mentiu a idade" << endl;

            return 0;
        }
    }

    cout << "idades corretas" << endl;
    return 0;
}