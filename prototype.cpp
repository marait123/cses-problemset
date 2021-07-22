
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
    freopen("case1.txt", "r", stdin);
    double a, b;
    double m = 3;
    a = .2 * m;

    b = .3 * 2;
    if (abs(a - b) < 1e-9)
    {
        printf("hello a = %.20f\n", abs(a - b));
    }
    return 0;
}