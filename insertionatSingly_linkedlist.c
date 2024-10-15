#include<stdio.h>
#include<stdlib.h>
 
 struct node{
    int data;
    struct node * next;
 };

 struct node* createnode(int x);
//function to insertion the node at the begining
 struct node* inseratbegining(struct node* head, int new_data){
    //create new node with the given data
    struct node* new_node = createnode(new_data);
     // Make the next of the new node point to the current
    // head
    new_node->next = head;
    // Return the new node as the new head of the list

    return new_node;
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
    struct node* head = createnode(8);
    head->next = createnode(3);
    head->next->next = createnode(4);
    head->next->next->next = createnode(5);
    head->next->next->next->next = createnode(6);

    int data = 1;
    head = inseratbegining(head, data);
    printlinked_list(head);

    return 0;
 }
