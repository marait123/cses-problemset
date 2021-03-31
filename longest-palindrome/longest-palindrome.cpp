#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{

    // freopen("case1.txt", "r", stdin);
    string str;
    cin >> str;
    int max_pal_index = 0;
    int max_pal_count = 0;
    // o(n**3)

    // another idea is to
    // use marching
    for (int i = 0; i < str.length(); i++)
    {
        int temp_count = 0;
        for (int j = str.length() - 1; j > i; j--)
        {
            int it1, it2;
            it1 = i;
            it2 = j;
            while (str[it1] == str[it2] && it2 >= it1)
            {
                it1++;
                it2--;
            }
            if ((j - i > temp_count) && it2 < it1)
            {
                temp_count = (j - i) + 1;
                break;
            }
        }

        if (temp_count > max_pal_count)
        {
            max_pal_count = temp_count;
            max_pal_index = i;
        }

        if (temp_count == str.length() - i)
            break;
    }

    cout << str.substr(max_pal_index, max_pal_count) << endl;

    return 0;
}