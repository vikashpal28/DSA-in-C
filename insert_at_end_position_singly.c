// C Program to Insert a Node at the End of Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int new_data);

// Function appends a new node at the end and returns the
// head.
struct Node* insertAtEnd(struct Node* head, int new_data)
{
    // Create a new node
    struct Node* new_node = createNode(new_data);

    // If the Linked List is empty, make
    // the new node as the head and return
    if (head == NULL) {
        return new_node;
    }

    // Store the head reference in a temporary variable
    struct Node* last = head;

    // Traverse till the last node
    while (last->next != NULL) {
        last = last->next;
    }

    // Change the next pointer of the last node
    // to point to the new node
    last->next = new_node;

    // Return the head of the list
    return head;
}

void printList(struct Node* node)
{
    while (node != NULL) {
        printf(" %d", node->data);
        node = node->next;
    }
}

struct Node* createNode(int new_data)
{
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

int main()
{
    // Create a linked list:
    // 2 -> 3 -> 4 -> 5 -> 6
    struct Node* head = createNode(2);
    head->next = createNode(3);
    head->next->next = createNode(4);
    head->next->next->next = createNode(5);
    head->next->next->next->next = createNode(6);

    head = insertAtEnd(head, 1);

    printList(head);

    return 0;
}

/*
NOTE:-
Time complexity: O(n), where n is the number of nodes in the linked list.
Auxiliary Space: O(1)
*/

/*
output
 2 3 4 5 6 1
*/