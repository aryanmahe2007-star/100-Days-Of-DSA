#include <stdio.h>

#define MAX 100

int main() {
    int arr[MAX];
    int front = -1, rear = -1;
    int n, m, i, x;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &x);

        if(front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }

        arr[rear] = x;
    }

    scanf("%d", &m);

    for(i = 0; i < m; i++) {
        if(front == -1) break;

        if(front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    if(front == -1)
        return 0;

    i = front;
    while(1) {
        printf("%d ", arr[i]);
        if(i == rear) break;
        i = (i + 1) % MAX;
    }

    return 0;
}