#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
#define MAX_N 100000

enum Color
{
    WHITE,
    GRAY,
    DARK
};
struct Node
{
    Color state = WHITE;
    vector<int> connections;
};

bool breadth_first(int n, vector<Node> &graph, vector<int> &path)
{
    for (int i = 0; i < graph[n].connections.size(); i++)
    {
        int index = graph[n].connections[i];
        if (graph[index].state == GRAY)
        {
            return false; // IMPOSSIBLE
        }
        else if (graph[index].state == WHITE)
        {
            // breadth first
            // make it gray
            graph[index].state = GRAY;
            bool is_possible = breadth_first(index, graph, path);
            if (!is_possible)
            {
                return false;
            }
            path.push_back(index);
            graph[index].state = DARK;
        }
        else
        {
            // this a cross edge
            // do nothing
        }
    }
    return true;
}

bool get_path(vector<Node> &graph, vector<int> &path)
{

    vector<int> temp_path;

    //
    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[i].state == WHITE)
        {
            // breadth first
            graph[i].state = GRAY;
            bool is_possible = breadth_first(i, graph, path);
            if (!is_possible)
            {
                return false;
            }
            path.push_back(i);
            graph[i].state = DARK;
        }
    }

    return true;
    /*
    for (int i = 0; i < graph.size(); i++)
    {
        graph[i].state = WHITE;
    }
    for (int i = 0; i < temp_path.size(); i++)
    {

        if (graph[temp_path[i]].state == WHITE)
        {
            graph[temp_path[i]].state = GRAY;
            breadth_first(temp_path[i], graph, path);
            graph[temp_path[i]].state = DARK;
        }
    }
*/
}

int main()
{
    // freopen("course.txt", "r", stdin);
    int N, M;
    cin >> N >> M;
    vector<Node> graph(N);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a - 1].connections.push_back(b - 1);
        // cout << a << " " << b << endl;
    }
    vector<int> result;

    bool is_possible = get_path(graph, result);
    if (is_possible)
    {
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[result.size() - i - 1] + 1 << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}