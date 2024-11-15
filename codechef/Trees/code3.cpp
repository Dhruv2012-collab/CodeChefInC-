#include <bits/stdc++.h>
using namespace std;

const int maxx = 100005;
vector <int> tree[maxx];

void dfs(int node) {
    cout << node << " ";
    for (auto i: tree[node]) {
        dfs(i);
    }
}

int main() {
    int n;
    cin >> n;
    
    
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
    }
    
    // Start DFS from the root node
    dfs(1);
}
