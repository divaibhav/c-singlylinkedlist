#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
// adding a node in linked list, adding as first node, inserting at head
void insertFirst(int data){
    //creating a node , to add in linked list
    struct node *link = (struct node*)malloc(sizeof(struct node));
    //setting data of node
    link -> data = data;
    //setting next to point to list refereed by head
    link -> next = head;
    //setting head to refer to new node (link)
    head = link;
}
//adding new node at the end
void insertLast(int data){
    struct node *link = (struct node*)malloc(sizeof(struct node));
    link -> data = data;
    if(head == NULL){
        link -> next = head;
        head = link;    
    }
    else{
        struct node *temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        link -> next = NULL;
        temp -> next = link;
    }



}
//struct node* deleteFirst()
int deleteFirst(){
    // storing deleted data
    int deletedData = head -> data;
    struct node *temp = head;
    //cahnging reference of head to second node by using head -> next
    head = head -> next;
    //breaking deleted node next link
    temp -> next = NULL;

    return deletedData;
    //return temp;

}
int length(){
    int length = 0;
    struct node *temp = head;
    while(temp != NULL){
        length ++;
        temp = temp -> next;
    }
    return length;
}
void traverse(){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d --> ",temp -> data);
        temp = temp -> next;
    }
    printf("NULL \n");
}

int search(int searchData){
    int found = 0;
    struct node *temp = head;
    while(temp != NULL){
        if(temp -> data == searchData){
            found = 1;
            break;
        }
        temp = temp -> next;
    }
    return found;

}


void main(){
    insertFirst(10);
    insertFirst(20);
    insertFirst(30);
    insertFirst(40);
    insertFirst(50);
    insertFirst(70);
    insertFirst(80);
    insertFirst(90);
    insertLast(150);
    printf("no of node in linked list = %d \n", length());
    printf("deleted data =  %d \n", deleteFirst());
    traverse();
    int found = search(500);
    if(found == 1){
        printf("Found");
    }
    else{
         printf("Not Found");
    }
}
