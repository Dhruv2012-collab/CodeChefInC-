#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 100005;
vector<int> tree[MAX_NODES];
bool visited[MAX_NODES];
int leafCount = 0;

void dfs(int node) {
    visited[node] = true;
    bool isLeaf = true;

    for (int neighbor : tree[node]) {
        if (!visited[neighbor]) {
            isLeaf = false;
            dfs(neighbor);
        }
    }

    if (isLeaf) {
        leafCount++;
    }
}

int main() {
    int N;
    cin >> N;

    int a, b;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    dfs(0);
    cout << leafCount << endl;

    return 0;
}
