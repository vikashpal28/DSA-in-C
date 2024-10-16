#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createnode(int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

struct node* insert_before(struct node* head, int key, int newdata) {
    if (head == NULL) {
        return NULL;
    }
    if (head->data == key) {
        struct node* newnode = createnode(newdata);
        newnode->next = head;
        return newnode;
    }

    struct node* cur = head;
    struct node* prev = NULL;
    while (cur != NULL && cur->data != key) {
        prev = cur;
        cur = cur->next;
    }

    if (cur != NULL) {
        struct node* newnode = createnode(newdata);
        prev->next = newnode;
        newnode->next = cur;
    }
    return head;
}

void printlinked_list(struct node* head) {
    struct node* curr = head;
    while (curr != NULL) {
        printf(" %d", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    struct node* head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(3);
    head->next->next->next = createnode(4);
    head->next->next->next->next = createnode(5);

    int newdata = 6;
    int key = 5;

    head = insert_before(head, key, newdata);
    printlinked_list(head);
    
    return 0;
}

/*
output
Time Complexity: O(n), where n is the number of nodes in the linked list.
Auxiliary Space: O(1)
*/

/*
output
 1 2 3 4 6 5
 */
