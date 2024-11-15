#include <bits/stdc++.h>
using namespace std;

int evaluateRPN(string s) {
    stack<int> st;
    
    for (char c : s) {
        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            
            if (c == '+') st.push(a + b);
            else if (c == '-') st.push(a - b);
            else if (c == '*') st.push(a * b);
        }
    }
    
    return st.top();
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        string expression;
        cin >> expression;
        
        cout << evaluateRPN(expression) << endl;
    }
    
    return 0;
}
