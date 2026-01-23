#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> run_dijkstras(vector<vector<pair<int, int>>> &adj, int start = 0)
{
    int n = adj.size();                                                   // the number of nodes
    vector<int> dist(n, 1e9);                                             // the array/vector to keep track of the distances
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // the pq to keep min dist

    dist[start] = 0;     // the start node is always 0
    pq.push({start, 0}); // add to pq
    while (!pq.empty())  // until pq is not empty
    {
        auto node = pq.top(); // take most min dist
        pq.pop();             // pop
        int u = node.first;   // take node val
        int d = node.second;  // take dist

        if (d > dist[u]) // if the curr dist > the currently tracked dist
        {
            continue;
        }

        // explore all neighbours
        for (auto neighbours : adj[u])
        {
            int v = neighbours.first;
            int v_d = neighbours.second;

            // relaxation
            int new_dist = dist[u] + v_d;
            if (new_dist < dist[v])
            {
                dist[v] = new_dist;
                pq.push({v, dist[v]});
            }
        }
    }

    cout << "Shortest path from " << start << ":\n";
    for (int i = 0; i < dist.size(); ++i)
    {
        cout << i << " - " << dist[i] << "\n";
    }
}

int main()
{
    vector<vector<pair<int, int>>> adj(6);

    adj[0] = {{1, 7}, {2, 12}};
    adj[1] = {{2, 2}, {3, 9}};
    adj[2] = {{4, 10}};
    adj[3] = {{5, 1}};
    adj[4] = {{3, 4}, {5, 5}};
    adj[5] = {{}};

    run_dijkstras(adj, 0);
}