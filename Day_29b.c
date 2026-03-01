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

// Function to add two numbers represented by linked lists
struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
    struct Node* dummy = createNode(0);
    struct Node* curr = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        curr->next = createNode(sum % 10);
        curr = curr->next;
    }

    return dummy->next;
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
    int n1, n2;
    scanf("%d", &n1);
    struct Node* l1 = NULL;
    for (int i = 0; i < n1; i++) {
        int val;
        scanf("%d", &val);
        insertEnd(&l1, val);
    }

    scanf("%d", &n2);
    struct Node* l2 = NULL;
    for (int i = 0; i < n2; i++) {
        int val;
        scanf("%d", &val);
        insertEnd(&l2, val);
    }

    struct Node* result = addTwoNumbers(l1, l2);
    printList(result);

    return 0;
}
