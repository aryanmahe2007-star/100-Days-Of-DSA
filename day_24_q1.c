#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to delete first occurrence of key
struct Node* deleteFirstOccurrence(struct Node* head, int key) {

    if (head == NULL)
        return head;

    // If head node itself holds the key
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* curr = head;
    struct Node* prev = NULL;

    while (curr != NULL && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    // If key not found
    if (curr == NULL)
        return head;

    // Remove node
    prev->next = curr->next;
    free(curr);

    return head;
}

// Function to print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, key, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &key);

    head = deleteFirstOccurrence(head, key);

    printList(head);

    return 0;
}