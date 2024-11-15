#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    stack<int> s;
    vector<int> result(n, -1);

    // Iterate the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from the stack while they are greater than or equal to arr[i]
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }

        // If stack is not empty, top is the next smaller element
        if (!s.empty()) {
            result[i] = s.top();
        }

        // Push current element onto the stack
        s.push(arr[i]);
    }

    // Print the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
