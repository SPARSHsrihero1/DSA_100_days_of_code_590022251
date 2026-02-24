#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to remove nodes with given value
struct ListNode* removeElements(struct ListNode* head, int val) {
    // Create a dummy node to simplify edge cases
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* current = dummy;

    while (current->next != NULL) {
        if (current->next->val == val) {
            // Remove the node
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }

    struct ListNode* newHead = dummy->next;
    free(dummy);
    return newHead;
}

// Helper function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Helper function to print the list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Example usage
int main() {
    // Construct linked list: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    struct ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(6);
    head->next->next->next = newNode(3);
    head->next->next->next->next = newNode(4);
    head->next->next->next->next->next = newNode(5);
    head->next->next->next->next->next->next = newNode(6);

    printf("Original list: ");
    printList(head);

    head = removeElements(head, 6);

    printf("After removing 6: ");
    printList(head);

    return 0;
}
