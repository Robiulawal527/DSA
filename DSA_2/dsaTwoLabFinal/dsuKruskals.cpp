#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) {
        this->u = u;
        this->v = v;
        this->weight = weight;
    }
};

vector<int> parents;
vector<int> ranks;

void make_set(int node) {
    parents[node] = node;
    ranks[node] = 0;
}

int find_parent(int node) {
    if (parents[node] == node) {
        return parents[node];
    }
    return parents[node] = find_parent(parents[node]);
}

void make_union(int a, int b) {
    int parent_a = find_parent(a);
    int parent_b = find_parent(b);
    if (parent_a != parent_b) {
        // if the rank of b is greater than the rank of a
        // then add a to b er group
        // and increase b er rank
        if (ranks[parent_b] > ranks[parent_a]) {
            parents[parent_a] = parent_b;
            ranks[parent_b]++;
        } else {
            // else, it means a er rank >= b er rank
            // add b to a er group
            // increase rank of a
            parents[parent_b] = parent_a;
            ranks[parent_a]++; 
        }
    }
}

bool comp(struct Edge* a, struct Edge* b) {
    return a->weight < b->weight;
}

void kruskals(vector<struct Edge*>& edges) {
    sort(edges.begin(), edges.end(), comp);
    int cost = 0;
    for(struct Edge* e : edges) {
        if ( find_parent(e->u) != find_parent(e->v) ) {
            cost += e->weight;
            cout << e->u << " --- " << e->v << " :: cost " << e->weight << "\n";
            make_union(e->u, e->v);
        }
    }

    cout << "Cost: " << cost << "\n";
}

int main() {
    vector<struct Edge*> nodes = {
        new Edge(1,2,2),
        new Edge(1,4,1),
        new Edge(2,4,3),
        new Edge(2,3,3),
        new Edge(1,5,4),
        new Edge(3,4,5),
        new Edge(2,6,7),
        new Edge(3,6,8),
        new Edge(4,5,9),
    };
    parents = vector<int>( nodes.size() + 1 );
    ranks = vector<int>( nodes.size() + 1 );
    // make set
    for (int i = 1; i < nodes.size(); ++i) {
        make_set(i);
    }
    kruskals(nodes);
} 