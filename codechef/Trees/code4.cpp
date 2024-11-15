#include <bits/stdc++.h>
using namespace std;

const int maxx = 100005;
vector<int> tree[maxx];

int main() {
    int n;
    cin >> n;
    
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
    }
    
    vector<bool> visited(maxx, false);
    queue<int> q;
    
  
    q.push(1);
    visited[1] = true;
    
    while (!q.empty()) {
        int a = q.front(); 
        q.pop();           
        cout << a << " "; 
        
        for (int neighbor : tree[a]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true; 
            }
        }
    }
    
    return 0;
}
