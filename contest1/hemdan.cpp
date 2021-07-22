
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
    int N, K;
    cin >> N >> K;
    vector<int> grades(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> grades[i];
    }
    int grade_sum = sum(grades);

    int intAvg = grade_sum / grades.size();

    int remainder = grade_sum - intAvg * grades.size();
    vector<char> after_decimal;

    for (size_t i = 0; i < K; i++)
    {
        int place = (remainder * 10) / N;
        remainder = remainder * 10 - place * N;
        after_decimal.push_back('0' + place);
    }
    cout << intAvg << ".";
    for (size_t i = 0; i < after_decimal.size(); i++)
    {
        cout << after_decimal[i];
    }
    cout << endl;
    return 0;
}