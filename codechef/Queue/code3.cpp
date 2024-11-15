#include <bits/stdc++.h>
using namespace std;

#define maxSize 101
int a[maxSize];
int front = 0; // Index of the front element
int rear = -1;  // Index of the rear element
int currentSize = 0;

bool isEmpty() {
    return currentSize == 0;
}

bool isFull() {
    return currentSize == maxSize;
}

int size() {
    return currentSize;
}

void enqueue(int item) {
    if (isFull()) {
        return;  // Queue is full
    }
    rear = (rear + 1) % maxSize; // Circular increment
    a[rear] = item;
    currentSize++;
}

int dequeue() {
    if (isEmpty()) {
        return -1;  // Queue is empty
    }
    int removedItem = a[front];
    front = (front + 1) % maxSize; // Circular increment
    currentSize--;
    return removedItem;
}

int main() {
    int n = 10;
    
    // Enqueueing odd numbers
    for (int i = 1; i <= n; i += 2) {
        enqueue(i);
    }
    
    // Enqueueing even numbers
    for (int i = 2; i <= n; i += 2) {
        enqueue(i);
    }

    // Dequeue and print the result
    for (int i = 0; i < n; ++i) {
        int item = dequeue();
        if (item != -1) {
            printf("%d ", item);
        }
    }
    
    return 0;
}
