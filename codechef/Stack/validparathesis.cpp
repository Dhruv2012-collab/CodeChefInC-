#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 101
char a[MAX_SIZE];
int top = -1;

void push(char ele){
    if(top < MAX_SIZE - 1){
        a[++top] = ele;
    }
}

char pop(){
    if(top >= 0){
        char ele = a[top];
        top--;
        return ele;
    }
    return '-1';
}

bool isEmpty(){
    return top == -1;
}

bool isFull(){
    return top >= MAX_SIZE;
}

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')');
}

bool isBalanced(string expression) {
    for (char ch : expression) {
        if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            if (isEmpty()) {
                return false;
            }
            pop();
        }
    }
    return isEmpty();
}

int main(){
    int t;
    cin >> t;

    while(t--){
        string str;
        cin >> str;
        cout << str << " : ";
        bool ans = isBalanced(str);
        if(ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
