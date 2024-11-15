#include <bits/stdc++.h>
using namespace std;

void reachableVertices(int N, int M, vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(N + 1);
    for (const auto& edge : edges) {
        int A = edge.first;
        int B = edge.second;
        graph[A].push_back(B);
    }

    set<int> visited;
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        if (visited.find(current) == visited.end()) {
            visited.insert(current);
            for (int neighbor : graph[current]) {
                if (visited.find(neighbor) == visited.end()) {
                    q.push(neighbor);
                }
            }
        }
    }

    vector<int> result(visited.begin(), visited.end());
    sort(result.begin(), result.end());

    for (int vertex : result) {
        cout << vertex << " ";
    }
    cout << endl;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> edges(M);
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }
    reachableVertices(N, M, edges);
    return 0;
}