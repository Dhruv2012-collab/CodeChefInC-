#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int T; // Number of test cases
    cin >> T;

    while (T--) {
        int N; // Size of the array
        cin >> N;
        vector<int> A(N);
        
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        int left = 0, right = N - 1;
        int operations = 0;

        while (left < right) {
            if (A[left] == A[right]) {
                left++;
                right--;
            } else if (A[left] < A[right]) {
                // If A[left] < A[right], we can split A[right] to match A[left]
                operations++;
                A[right] -= A[left]; // Reduce A[right] to match A[left]
                left++;
            } else { // A[left] > A[right]
                // If A[left] > A[right], we can split A[left] to match A[right]
                operations++;
                A[left] -= A[right]; // Reduce A[left] to match A[right]
                right--;
            }
        }

        cout << operations << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}