
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

struct Monster
{
    int stamina;
    int health;
    int wealth;
};

bool compareTwoMonsters(Monster a, Monster b)
{
    return a.wealth >= b.wealth;
}

int main()
{
    // freopen("case1.txt", "r", stdin);
    int gold = 0;
    int N, H, S;
    cin >> N >> H >> S;
    vector<Monster> monsters(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> monsters[i].health >> monsters[i].stamina >> monsters[i].wealth;
    }

    sort(monsters.begin(), monsters.end(), compareTwoMonsters);

    for (size_t i = 0; i < monsters.size(); i++)
    {
        if (H - monsters[i].health > 0 && ((S + H - monsters[i].health) - monsters[i].stamina) > 0)
        {
            H -= monsters[i].health;
            S -= monsters[i].stamina;
            if (S < 0)
            {
                H += S;
                S = 0;
            }
            gold += monsters[i].wealth;
        }
    }
    cout << gold << endl;

    return 0;
}