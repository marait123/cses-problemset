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

    vector<int> window(K);
    for (int j = 0; j < K; j++)
    {
        window[j] = num_vec[j];
    }
    // TODO: optimize the sort as we can use
    // previously sorted array for the next window
    sort(window.begin(), window.end());

    for (int i = 0; i < N - K + 1; i++)
    {
        // put num_vec[i] in the sorted window

        // use binary search to find num_vec[i]
        // then replace 
        /*window[0] = num_vec[i];
        int j = 0;
        while (j < K - 1 && window[j] > num_vec[j + 1])
        {
            num_vec[j + 1] = num_vec[j];
            j++;
        }*/

        int median = -1;
        // find the median value in the
        median = window[K / 2];
        // window

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