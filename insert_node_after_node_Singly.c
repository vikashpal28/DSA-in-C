#include<stdio.h>
#include<stdlib.h>

 struct node {
    int data;
    struct node* next;
 };
 struct node* createnode(int data);

 // Function to insert a new node after a given node
 struct node* insertAfter(struct node * head, int key, int new_data){
   struct node* curr = head;
   // Iterate over Linked List to find the key
   while(curr!=NULL){
    if(curr->data==key)
    break;
    curr = curr->next;
   }
// If curr becomes NULL means, given key is not found
  if(curr == NULL)
  return head;
  // Allocate new node by given data and point
  // the next of newNode to curr's next &
  // point current next to newNode
  struct node* new_node = createnode(new_data);
  new_node->next = curr->next;
  curr->next = new_node;
  return head;

 }
  void printlinked_list(struct node* head){
    struct node* curr = head;
    while(curr!=NULL){
        printf(" %d",curr->data);
        curr = curr->next;
    }
    printf("\n");
 }
 struct node* createnode(int new_data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
 }
 int main(){
    struct node* head = createnode(2);
    head->next = createnode(3);
    head->next->next = createnode(5);
    head->next->next->next = createnode(6);
   // head->next->next->next->next = createnode(6);

    int key = 6,new_data = 4;
    head = insertAfter(head,key, new_data);
    printlinked_list(head);
 }