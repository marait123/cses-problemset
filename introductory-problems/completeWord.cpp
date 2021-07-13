// https://codeforces.com/group/zvsr84He8w/contest/315331/problem/T
// https://codeforces.com/group/zvsr84He8w/contest/315331/problem/A
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <queue>

#include <map>
using namespace std;
#define MAX_N 100000
#define LL long long
#define OO INT32_MAX
int main()
{
    freopen("case1.txt", "r", stdin);
    char alphabet[26];
    string nice_str;
    cin >> nice_str;
    // alphabet[0] = 'A';
    map<char, int> alpha_map;

    for (size_t i = 0; i < 26; i++)
    {
        alpha_map.insert(pair<char, int>('A' + i, 0));
    }

    int curr_index = 0, count = 0;
    while (curr_index < nice_str.length() - 25)
    {
        for (size_t i = 0; i < 26; i++)
        {
            alpha_map['A' + i] = 0;
        }
        count = 0;
        int not_possible = false;
        int unknown_count = 0;
        for (size_t i = curr_index; i < curr_index + 26; i++)
        {
            if (alpha_map[nice_str[i]] == 1 && nice_str[i] != '?')
            {
                not_possible = true;
                break;
            }
            else
            {
                if (nice_str[i] == '?')
                    unknown_count++;
                count += 1;
                alpha_map[nice_str[i]] = 1;
            }
        }
        if (count == 26)
        {
            // cout << "nice";
            vector<char> missing_chars;
            int last_unkown_index = 0;
            for (size_t i = 0; i < 26; i++)
            {
                if (alpha_map['A' + i] == 0)
                {
                    missing_chars.push_back('A' + i);
                }
            }

            for (size_t i = curr_index; i < count; i++)
            {
                if (nice_str[i] == '?')
                {
                    cout << missing_chars[last_unkown_index++];
                }
                else
                {
                    cout << nice_str[i];
                }
            }

            break;
        }
        curr_index += 1;
    }
    if (count != 26)
    {
        cout << -1;
    }
    cout << endl;
    return 0;
}