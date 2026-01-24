#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> dijkstra(vector<vector<int>>& graph, int src) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0) {
                int newDist = dist[u] + graph[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    return dist;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> T(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> T[i][j];

    int M;
    cin >> M;

    while (M--) {
        int S, G, D;
        cin >> S >> G >> D;

        vector<int> distS = dijkstra(T, S);
        vector<int> distG = dijkstra(T, G);

        int actualTime = distS[G] + distG[D];
        int directTime = distS[D];
        int savedTime = actualTime - directTime;

        cout << actualTime << " " << savedTime << "\n";
    }

    return 0;
}
