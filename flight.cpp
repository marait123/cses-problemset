
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

int K;
int minW;
int maxW;
int boxNum;

void boxes(vector<int> &weights, int weight, int index, int currK)
{
    if (index > weights.size() || currK > K)
    {
        return;
    }
    if (currK == K)
    {
        if (weight >= minW && weight <= maxW)
        {

            boxNum++;
        }
        return;
    }

    boxes(weights, weight + weights[index], index + 1, currK + 1);
    boxes(weights, weight, index + 1, currK);
}

int main()
{
    // freopen("case1.txt", "r", stdin);
    // this is my version
    int N;
    cin >> N >> K;
    vector<int> weights(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> weights[i];
    }
    cin >> minW >> maxW;
    boxes(weights, 0, 0, 0);
    cout << boxNum << endl;
    return 0;
}