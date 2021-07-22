
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
    // freopen("case1.txt", "r", stdin);

    int t;
    cin >> t;

    for (size_t i = 0; i < t; i++)

    {
        int N, K;
        cin >> N >> K;

        vector<int> old_vec(N);

        ll min_val = INT32_MAX;
        ll max_val = INT32_MIN;
        for (size_t i = 0; i < N; i++)
        {
            cin >> old_vec[i];
        }
        int vec_sum = sum(old_vec);
        for (int i = 0; i < K; i++)
        {
            int old_sum = 0;
            for (size_t j = 0; j < N; j++)
            {
                old_vec[j] = vec_sum - old_vec[j];

                old_sum += old_vec[j];
            }
            vec_sum = old_sum;
        }

        // now find the maximum difference
        // sort(old_vec.begin(), old_vec.end());
        for (size_t i = 0; i < old_vec.size(); i++)
        {
            if (old_vec[i] <= min_val)
            {
                min_val = old_vec[i];
            }
            if (old_vec[i] >= max_val)
            {
                max_val = old_vec[i];
            }
        }

        cout << abs(max_val - min_val) << endl;
    }

    return 0;
}