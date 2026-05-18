// Implement main program.
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Dijkstra's Algorithm
void dijkstra(const vector<vector<pair<int, int>>>& graph, int source) {
    int V = graph.size();

    // Distance array
    vector<int> dist(V, INT_MAX);

    // Min-heap: {distance, vertex}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Source initialization
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        // Skip outdated entries
        if (currentDist > dist[currentNode])
            continue;

        // Traverse neighbors
        for (auto edge : graph[currentNode]) {
            int neighbor = edge.first;
            int weight = edge.second;

            // Relaxation step
            if (dist[currentNode] + weight < dist[neighbor]) {
                dist[neighbor] = dist[currentNode] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    // Print shortest distances
    cout << "Shortest distances from source " << source << ":\n";

    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": ";

        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }
}

int main() {

    // Generate graph
    const int V = 6;

    vector<vector<pair<int, int>>> graph(V); //Adjacency list

    graph[0].push_back({1, 4});
    graph[0].push_back({2, 9});
    graph[0].push_back({4, 2});

    graph[1].push_back({3, 1});
    graph[1].push_back({2, 2});

    graph[2].push_back({3, 7});
    graph[2].push_back({5, 4});

    graph[3].push_back({5, 1});

    graph[4].push_back({2, 3});
    graph[4].push_back({5, 8});

    //Print graph
    for (int i = 0; i < V; i++) 
    {
        cout << "Vertex " << i << ":\n";

        for (auto edge : graph[i]) 
        {
            cout << "  -> " << edge.first << " (weight " << edge.second << ")\n";
        }
    }

    //starting node is 0
    dijkstra(graph, 0);

    return 0;
}