
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
#define OO INT32_MAX / 3

int main()
{
    freopen("case1.txt", "r", stdin);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {

        int V, Q;
        cin >> V >> Q;
        vector<vector<int>> graph(V, vector<int>(V, OO));
        vector<vector<int>> dist(V, vector<int>(V, OO));
        for (int i = 0; i < V; i++)
        {
            int src, dst, weight;
            cin >> src >> dst >> weight;
            graph[src - 1][dst - 1] = weight;
            graph[i][i] = 0;
            dist[i][i] = 0;
        }

        int i, j, k;
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                dist[i][j] = graph[i][j];

        for (k = 0; k < V; k++)
        {
            for (i = 0; i < V; i++)
            {
                for (j = 0; j < V; j++)
                {
                    // if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != OO && dist[i][k] != OO))
                    //     dist[i][j] = dist[i][k] + dist[k][j];
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        for (size_t k = 0; k < Q; k++)
        {
            int a, b;
            cin >> a >> b;
            cout << dist[a - 1][b - 1] << endl;
        }
    }

    return 0;
}