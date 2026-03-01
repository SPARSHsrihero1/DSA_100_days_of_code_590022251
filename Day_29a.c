#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at the end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to rotate linked list right by k places
struct Node* rotateRight(struct Node* head, int k) {
    if (!head || k == 0) return head;

    // Find length of list
    int length = 1;
    struct Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    // Make it circular
    tail->next = head;

    // Effective rotations
    k = k % length;
    int stepsToNewHead = length - k;

    // Find new head
    struct Node* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }

    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

// Function to print linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, k;
    scanf("%d", &n);

    struct Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        insertEnd(&head, val);
    }

    scanf("%d", &k);

    head = rotateRight(head, k);
    printList(head);

    return 0;
}
