
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

template <typename T>
T sum(vector<T> &vec)
{
    T res = 0;
    for (size_t i = 0; i < vec.size(); i++)
    {
        res += vec[i];
    }
    return res;
}
int main()
{
    freopen("case1.txt", "r", stdin);

    int t;
    cin >> t;
    for (size_t i = 0; i < t; i++)

    {
        int N, K;
        cin >> N >> K;

        vector<int> old_vec(N);

        for (size_t i = 0; i < N; i++)
        {
            cin >> old_vec[i];
        }
        for (int i = 0; i < K; i++)
        {
            int vec_sum = sum(old_vec);
            for (size_t j = 0; j < N; j++)
            {
                old_vec[j] = vec_sum - old_vec[j];
            }
        }

        // now find the maximum difference
        sort(old_vec.begin(), old_vec.end());
        cout << abs(old_vec[N - 1] - old_vec[0]) << endl;
    }

    return 0;
}