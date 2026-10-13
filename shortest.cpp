#include <iostream>
#include <climits>
using namespace std;

#define V 5

int main()
{
    int graph[V][V] = {0};
    int edges, cost;
    char u, v, source, dest;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges and cost (A B 4):\n";

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> cost;

        if (u >= 'a' && u <= 'e') u -= 32;
        if (v >= 'a' && v <= 'e') v -= 32;

        if (u < 'A' || u > 'E' ||
            v < 'A' || v > 'E' || cost <= 0)
        {
            cout << "Invalid input!";
            return 1;
        }

        graph[u - 'A'][v - 'A'] = cost;
    }

    cout << "Enter source: ";
    cin >> source;

    cout << "Enter destination: ";
    cin >> dest;

    if (source >= 'a' && source <= 'e') source -= 32;
    if (dest >= 'a' && dest <= 'e') dest -= 32;

    if (source < 'A' || source > 'E' ||
        dest < 'A' || dest > 'E')
    {
        cout << "Invalid vertex!";
        return 1;
    }

    int dist[V];
    bool visited[V] = {false};

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[source - 'A'] = 0;

    for (int i = 0; i < V; i++)
    {
        int u = -1, mn = INT_MAX;

        for (int j = 0; j < V; j++)
        {
            if (!visited[j] && dist[j] < mn)
            {
                mn = dist[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    int d = dest - 'A';

    if (dist[d] == INT_MAX)
        cout << "No path exists!";
    else
        cout << "Shortest distance from " << source
             << " to " << dest << " = " << dist[d];

    return 0;
}