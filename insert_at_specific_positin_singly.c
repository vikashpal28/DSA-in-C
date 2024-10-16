// C Program to Insert a Node At a Specific Position in
// Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data);

// Function to insert a node at a specific position in the
// linked list
struct Node* insertAtPosition(struct Node* head,
                              int position, int data) {
    struct Node* newNode = createNode(data);

    // If inserting at the beginning
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    struct Node* current = head;
    for (int i = 1; i < position - 1 && current != NULL;++i) {
        current = current->next;
    }

    // If the position is out of bounds
    if (current == NULL) {
        printf("Position is out of bounds.\n");
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf(" %d", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* createNode(int data) {
    struct Node* newNode
        = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
  
    // Creating the list 3->5->8->10
    struct Node* head = createNode(3);
    head->next = createNode(5);
    head->next->next = createNode(8);
    head->next->next->next = createNode(10);

    int data = 12, pos = 3;
    head = insertAtPosition(head, pos, data);
 
    printList(head);

    return 0;
}

/*
note:-
Time complexity: O(n), where n is the number of nodes in the linked list.
Auxiliary Space: O(1)
*/

/*
output
 3 5 12 8 10
 */
