#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack, int N) {
    return stack->top == N - 1;
}

void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

int peek(struct Stack* stack) {
    return stack->array[stack->top];
}

long max(long a, long b) {
    return (a > b) ? a : b;
}

long largestRectangleArea(int* heights, int n) {
    struct Stack* stack = createStack(n);
    long maxArea = 0;
    int i = 0;

    while (i < n) {
        if (isEmpty(stack) || heights[peek(stack)] <= heights[i]) {
            push(stack, i++);
        }
        else {
            int top = pop(stack);
            long area = (long)heights[top] * (isEmpty(stack) ? i : i - peek(stack) - 1);
            maxArea = max(maxArea, area);
        }
    }

    while (!isEmpty(stack)) {
        int top = pop(stack);
        long area = (long)heights[top] * (isEmpty(stack) ? i : i - peek(stack) - 1);
        maxArea = max(maxArea, area);
    }

    free(stack->array);
    free(stack);
    return maxArea;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);
        int* heights = (int*)malloc(n * sizeof(int));
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &heights[i]);
        }

        printf("%ld\n", largestRectangleArea(heights, n));

        free(heights);
    }

    return 0;
}
