#include <bits/stdc++.h>
using namespace std;

#define maxSize 10 // Maximum number of tasks
int taskList[maxSize]; // Array to hold tasks
int taskListSize = 0; // Current size of the task list

void addTask(int task) {
    // Check if the task is already present
    for (int i = 0; i < taskListSize; i++) {
        if (taskList[i] == task) {
            return; // Task already exists, ignore it
        }
    }
    // If not present, add the task
    if (taskListSize < maxSize) {
        taskList[taskListSize++] = task; // Add task and increment size
    }
}

void displayToDoList() {
    for (int i = 0; i < taskListSize; i++) {
        cout << taskList[i] << endl; // Print each task on a new line
    }
}

int main() {
    int n;
    // Read up to 10 tasks from input and add them to the to-do list
    for (int i = 0; i < maxSize; i++) {
        int task;
        cin >> task; // Read task input
        addTask(task); // Add task to the list
    }

    // Display the current to-do list
    displayToDoList();

    return 0;
}