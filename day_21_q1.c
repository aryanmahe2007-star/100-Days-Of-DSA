#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0) return 0;

    int value;
    scanf("%d", &value);

    // Create head node
    struct Node* head = createNode(value);
    struct Node* temp = head;

    // Insert remaining nodes
    for (int i = 1; i < n; i++) {
        scanf("%d", &value);
        temp->next = createNode(value);
        temp = temp->next;
    }

    // Traverse and print
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}