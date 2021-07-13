#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
#define MAX_N 100000

int main()
{
    long long N = -1;
    // freopen("case1.txt", "r", stdin);
    cin >> N;
    // vector<int> numVec(N);

    while (N != 1)
    {
        cout << N << " ";
        if (N % 2 == 0)
        {
            N /= 2;
        }
        else
        {
            N = 3 * N + 1;
        }
    }
    cout << N << endl;
    return 0;
}