
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
class Solution
{
public:
    static string longestPalindrome(string s)
    {
        int longest_index = 0;
        int longest_length = 0;

        for (int start = 0; start < s.length(); start++)
        {
            if (s.length() - start + 1 <= longest_length)
            {
                break;
            }
            bool pal = false;

            for (int end = s.length() - 1; end >= 0 && !pal; end--)
            {
                int i = start, j = end;
                int current_length = 0;
                while (j >= start && s[i] == s[j])
                {
                    current_length++;
                    i++;
                    j--;
                }
                if (j < start && current_length > longest_length)
                {
                    longest_length = current_length;
                    longest_index = start;
                    pal = true;
                }
            }
        }

        return s.substr(longest_index, longest_length);
    }
};
int main()
{
    freopen("case1.txt", "r", stdin);
    string s;
    cin >> s;
    string res = Solution::longestPalindrome(s);
    cout << res << endl;
    return 0;
}