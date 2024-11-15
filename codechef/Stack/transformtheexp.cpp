#include <bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isLeftAssociative(char op) {
    return op != '^';
}

void infixToPostfix(string expression) {
    stack<char> s;
    string result = "";

    for (char ch : expression) {
        if (isalnum(ch)) {
            result += ch;
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                result += s.top();
                s.pop();
            }
            s.pop();
        } else {
            while (!s.empty() && precedence(s.top()) >= precedence(ch) && isLeftAssociative(ch)) {
                result += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        result += s.top();
        s.pop();
    }

    cout << result << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string expression;
        cin >> expression;
        infixToPostfix(expression);
    }

    return 0;
}
