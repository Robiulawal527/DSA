#include <iostream>
#include <vector>
using namespace std;    

    vector<int> parent, ranks;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) return;

        if (ranks[pa] < ranks[pb])
            parent[pa] = pb;
        else if (ranks[pa] > ranks[pb])
            parent[pb] = pa;
        else {
            parent[pb] = pa;
            ranks[pa]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;

        parent.resize(n);
        ranks.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto &c : connections)
            unite(c[0], c[1]);

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i)
                components++;
        }

        return components - 1;
    }

int main() {
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}};
    cout << makeConnected(n, connections) << endl;
    return 0;
}

