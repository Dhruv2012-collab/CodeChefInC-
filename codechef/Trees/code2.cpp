#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    // This is our adjacency list
    vector <int> tree[n];
    
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        
        // Adding an edge from u to v
        tree[u].push_back(v);
        
    }
    
    // Complete the code to print the adjacency list
    for (int i = 0; i < n - 1; i++) {
    for (int neighbor : tree[i]) {
            cout << neighbor << " ";
        }
    }
    return 0;
}