#include <iostream>
#include <vector>
using namespace std;

    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb)
            parent[pa] = pb;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto &e : edges)
            unite(e[0], e[1]);

        return find(source) == find(destination);
    }