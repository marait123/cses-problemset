#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("case1.txt", "r", stdin);
    int N, K;
    cin >> N >> K;
    vector<int> num_vec(N);
    for (int i = 0; i < N; i++)
    {
        cin >> num_vec[i];
    }

    for (int i = 0; i < N - K + 1; i++)
    {
        int median = -1;
        // find the median value in the
        // window
        vector<int> window(K);
        for (int j = 0; j < K; j++)
        {
            window[j] = num_vec[i + j];
        }
        sort(window.begin(), window.end());
        median = window[K / 2];

        int out = 0;
        // sigma(|x-median|) for every
        // x in the window
        for (auto it = window.begin(); it != window.end(); it++)
        {
            out += abs((*it) - median);
        }
        cout << out << " ";
    }
    cout << endl;
    return 0;
}