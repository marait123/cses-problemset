// https://cses.fi/problemset/task/1193
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
#define LL long long
#define OO INT32_MAX

struct node
{
    int row;
    int col;
    char dir;
};
int main()
{
    freopen("case1.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    node start_node;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                start_node.row = i;
                start_node.col = j;
                start_node.dir = 'x';
            }
        }
    }
    queue<node> search_queue;

    vector<vector<bool>> processed(n, vector<bool>(m, false));
    vector<vector<node>> parents(n, vector<node>(m));

    search_queue.push(start_node);
    bool found = false;
    while (!search_queue.empty())
    {
        node current_node = search_queue.front();
        search_queue.pop();
        int row = current_node.row;
        int col = current_node.col;
        if (processed[row][col])
        {

            throw "node is already processed";
        }
        processed[row][col] = true;

        if (grid[row][col] == 'B')
        {
            found = true;
            // cout << "path was found" << endl;
            int curr_row = row;
            int curr_col = col;
            // stack<node> node_stack;
            stack<char> directions;
            directions.push(current_node.dir);
            while (!(curr_row == start_node.row && curr_col == start_node.col))
            {
                node temp_node = parents[curr_row][curr_col];
                curr_row = temp_node.row;
                curr_col = temp_node.col;

                // cout << temp_node.dir << " ";
                if (temp_node.dir != 'x')
                {
                    directions.push(temp_node.dir);
                }
            }
            cout << "YES" << endl;
            cout << directions.size() << endl;
            while (!directions.empty())
            {
                cout << directions.top();
                directions.pop();
            }
            cout << endl;
            return 0;
        }

        if (grid[row][col] == '#')
        {
            throw "error you are trying to use #";
        }
        // add up
        if (row - 1 >= 0 && !processed[row - 1][col] && grid[row - 1][col] != '#')
        {
            node n = {row : row - 1, col : col, dir : 'U'};
            parents[row - 1][col] = current_node;
            search_queue.push(n);
        }
        // add left
        if (col - 1 >= 0 && !processed[row][col - 1] && grid[row][col - 1] != '#')
        {

            node n = {row : row, col : col - 1, dir : 'L'};
            parents[row][col - 1] = current_node;

            search_queue.push(n);
        }

        // add down

        if (row + 1 < n && !processed[row + 1][col] && grid[row + 1][col] != '#')
        {
            node n = {row : row + 1, col : col, dir : 'D'};
            parents[row + 1][col] = current_node;
            search_queue.push(n);
        }

        // add right
        if (col + 1 < m && !processed[row][col + 1] && grid[row][col + 1] != '#')
        {

            node n = {row : row, col : col + 1, dir : 'R'};
            parents[row][col + 1] = current_node;

            search_queue.push(n);
        }
    }
    cout << "NO" << endl;
    return 0;
}

// 5 8
// ########
// #.A#...#
// #.##.#B#
// #......#
// ########

// 5 8
// ########
// A..#...#
// #.##.#B#
// #......#
// ########