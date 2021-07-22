
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
    vector<int> track_scores = {15,
                                12,
                                10,
                                9,
                                1};
    vector<int> track_numbers = {1,
                                 2,
                                 3,
                                 4,
                                 12};
    int size = track_numbers.size();
    vector<int> tracks;
    int old_div = N;
    int new_div = N;
    queue<int> tracks_queue;
    for (int i = 0; i < size; i++)
    {
        int temp_div = old_div / track_scores[i];
        if (temp_div == 0)
            continue;
        new_div = old_div - temp_div * track_scores[i];

        // cout << old_div << endl;
        for (size_t j = 0; j < temp_div; j++)
        {
            tracks_queue.push(track_numbers[i]);
        }

        old_div = new_div;
    }
    cout << tracks_queue.size() << endl;
    while (!tracks_queue.empty())
    {
        cout << tracks_queue.front() << " ";
        tracks_queue.pop();
    }

    cout << endl;
}