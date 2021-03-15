#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
enum COLOR
{
    WHITE,
    GREY,
    DARK
};
struct Node
{
    COLOR color;
    vector<int> adjacents;
};
bool find_cycle(vector<Node> &graph, int start = 0)
{
    for (size_t i = 0; i < graph[start].adjacents.size(); i++)
    {
        int index = graph[start].adjacents[i];
        if (graph[index].color == WHITE)
        {
            graph[index].color = GREY;
            bool cycle_found = find_cycle(graph, index);
            if (cycle_found == true)
            {
                return true;
            }

            graph[index].color = DARK;
        }
        else if (graph[index].color == GREY)
        {
            return true;
        }
        // else it is already visited so do nothing
    }
    return false;
}
int main()
{
    freopen("cycle2.txt", "r", stdin);
    int N, M;
    cin >> N >> M;
    vector<Node> graph(N);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].adjacents.push_back(b);
    }
    bool cycle_found = find_cycle(graph, 0);
    cout << (cycle_found ? "yes" : "No") << endl;
    return 0;
}