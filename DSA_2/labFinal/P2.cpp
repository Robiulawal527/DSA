#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    string u, v, safety;
    int weight;
};

vector<int> parent, rankv;

int find_set(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find_set(parent[x]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rankv[a] < rankv[b])
            parent[a] = b;
        else if (rankv[a] > rankv[b])
            parent[b] = a;
        else {
            parent[b] = a;
            rankv[a]++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> city(n);
    for (int i = 0; i < n; i++)
        cin >> city[i];

    vector<Edge> edges;

    for (int i = 0; i < m; i++) {
        Edge e;
        cin >> e.u >> e.v >> e.weight >> e.safety;
        if (e.safety == "safe")
            edges.push_back(e);
    }

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    parent.resize(n);
    rankv.resize(n, 0);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int totalCost = 0;
    cout << "The selected edges:\n";

    for (auto e : edges) {
        int u = find(city.begin(), city.end(), e.u) - city.begin();
        int v = find(city.begin(), city.end(), e.v) - city.begin();

        if (find_set(u) != find_set(v)) {
            union_set(u, v);
            totalCost += e.weight;
            cout << "(" << e.u << "," << e.v << "," << e.weight << ",safe)\n";
        }
    }

    cout << "Total weight of the MST: " << totalCost << "\n";
    return 0;
}
