#include <bits/stdc++.h>
using namespace std;

int shortestRoute(int N, int M, vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(N + 1);
    for (const auto& edge : edges) {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
    }

    vector<int> distance(N + 1, -1);
    queue<int> q;
    q.push(1);
    distance[1] = 1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int neighbor : graph[current]) {
            if (distance[neighbor] == -1) {
                distance[neighbor] = distance[current] + 1;
                q.push(neighbor);
                if (neighbor == N) {
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
    cout << shortestRoute(N, M, edges) << endl;
    return 0;
}