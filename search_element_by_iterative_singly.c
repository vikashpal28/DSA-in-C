#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createnode(int new_data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data =new_data;
    newnode->next = NULL;
    return newnode;
}

bool searchkey(struct node* head, int key){
    struct node* curr = head;
    if(curr!=NULL){
        if(curr->data == key){
        return true;
        curr = curr->next;
        }
    }
    return false;
}
int main(){
    struct node* head = createnode(2);
    head->next = createnode(3);
     head->next->next = createnode(4);
      head->next->next->next = createnode(5);
      int key = 2;
      if(searchkey(head,key)){
        printf("yes");
      }
      else{
        printf("no");
      }
      return 0;

}
/*
NOTE:-
Time Complexity: O(N), Where N is the number of nodes in the Linked List.
Auxiliary Space: O(1)
*/

