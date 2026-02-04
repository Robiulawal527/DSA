
#include <iostream>
#include <vector>
#include <string>
using namespace std;

static vector<int> parent;
static vector<int> rankv;

void makeSet(int v){
    if (v <= 0) return;
    if (v >= (int)parent.size()){
        int old = parent.size();
        parent.resize(v+1);
        rankv.resize(v+1);
        for (int i = old; i <= v; ++i) parent[i] = i, rankv[i]=0;
    }
    parent[v] = v;
    rankv[v] = 0;
}

int find(int v){
    if (v <= 0 || v >= (int)parent.size()) return -1;
    if (parent[v] == v) return v;
    parent[v] = find(parent[v]);
    return parent[v];
}

bool unite(int a,int b){
    if (a <= 0 || b <= 0) return false;
    if (a >= (int)parent.size() || b >= (int)parent.size()) return false;
    a = find(a); b = find(b);
    if (a == -1 || b == -1) return false;
    if (a == b) return false;
    if (rankv[a] < rankv[b]) swap(a,b);
    parent[b] = a;
    if (rankv[a] == rankv[b]) rankv[a]++;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0; // initial elements (1..n)
    if (n > 0) {
        parent.assign(n+1,0);
        rankv.assign(n+1,0);
        for (int i=1;i<=n;i++) parent[i]=i;
    }

    int q;
    if (!(cin >> q)) return 0; // number of operations
    while (q--) {
        string cmd; cin >> cmd;
        if (cmd == "make") { int x; cin >> x; makeSet(x); }
        else if (cmd == "find") { int x; cin >> x; cout << find(x) << '\n'; }
        else if (cmd == "union") { int a,b; cin >> a >> b; unite(a,b); }
        else if (cmd == "print") {
            int sz = (int)parent.size()-1;
            if (sz <= 0) { cout << "(no elements)\n"; continue; }
            cout << "Parents:";
            for (int i=1;i<=sz;i++) cout << ' ' << parent[i];
            cout << '\n';
            cout << "Ranks:";
            for (int i=1;i<=sz;i++) cout << ' ' << rankv[i];
            cout << '\n';
        }
    }

    return 0;
}


