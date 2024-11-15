#include <iostream>
#include <vector>

using namespace std;

void rotate_necklace() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<int> pearls(n);
        for (int i = 0; i < n; ++i) {
            cin >> pearls[i];
        }

        k = k % n;
        vector<int> new_pearls(n);
        for (int i = 0; i < n; ++i) {
            new_pearls[i] = pearls[(i + k) % n];
        }

        for (int i = 0; i < n; ++i) {
            cout << new_pearls[i] << (i == n - 1 ? "\n" : " ");
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    rotate_necklace();

    return 0;
}