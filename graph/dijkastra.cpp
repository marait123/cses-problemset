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
void dikastra(vector<vector<pair<int, int>>> &adj, vector<int> &parents)
{
    vector<int> distances(adj.size(), OO);
    vector<bool> processed(adj.size(), false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_distance_node;
    distances[0] = 0;
    // insert node 0 with distance 0
    pq_distance_node.push(pair<int, int>(0, 0));
    while (!pq_distance_node.empty())
    {
        pair<int, int> node = pq_distance_node.top();
        pq_distance_node.pop();

        if (processed[node.second])
        {
            continue;
        }

        processed[node.second] = true;
        int w = node.first, a = node.second;

        // relax
        for (auto adj_node : adj[a])
        {
            if (w + adj_node.first < distances[adj_node.second])
            {
                distances[adj_node.second] = w + adj_node.first;
                parents[adj_node.second] = a;
                pq_distance_node.push(pair<int, int>(distances[adj_node.second], adj_node.second));

                // insert the node second and its weight
            }
        }
    }
}
void print_parents(int current_node, vector<int> parents)
{
    if (current_node == -1)
    {
        return;
    }
    else
    {
        print_parents(parents[current_node], parents);
        cout << current_node + 1 << " ";
    }
}
int main()
{
    freopen("case1.txt", "r", stdin);
    int n, m;
    cin >> n;
    cin >> m;
    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
    vector<int> parents(n, -1);

    for (size_t i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a - 1].push_back(pair<int, int>(w, b - 1));
    }
    dikastra(adj, parents);
    if (parents[parents.size() - 1] == -1)
    {
        cout << -1 << endl;
    }
    else
    {
        int current_node = parents.size() - 1;

        print_parents(current_node, parents);
        cout << endl;
    }
    return 0;
}