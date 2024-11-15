#include <bits/stdc++.h>
using namespace std;

int minimumDistance(int N, int M, vector<pair<int, int>>& edges, int x, int y) {
    vector<vector<int>> graph(N + 1);
    for (const auto& edge : edges) {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
    }

    vector<int> distance(N + 1, -1);
    queue<int> q;
    q.push(x);
    distance[x] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int neighbor : graph[current]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[current] + 1;
                q.push(neighbor);
                if (neighbor == y) {
                    return distance[neighbor];
                }
            }
        }
    }
    return -1;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> edges(M);
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }
    int x, y;
    cin >> x >> y;
    cout << minimumDistance(N, M, edges, x, y) << endl;
    return 0;
}