#include <bits/stdc++.h>
using namespace std;

void solve() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        deque<int> pile(N);
        for (int i = 0; i < N; ++i) {
            cin >> pile[i];
        }

        int turn = 0;

        while (pile.size() > 1) {
            if (turn == 0) {
                pile.push_back(pile.front());
                pile.pop_front();
                pile.pop_front();
            } else {
                pile.push_back(pile.front());
                pile.pop_front();
                pile.push_back(pile.front());
                pile.pop_front();
                pile.pop_front();
            }
            turn = 1 - turn;
        }

        int last_stone = pile.front();
        cout << turn << " " << last_stone << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}