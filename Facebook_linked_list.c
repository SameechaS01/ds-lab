#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head;

void insert(int likes){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = likes;
    ptr -> next = head;
    ptr -> prev = NULL;
    if(head!=NULL){
        head->prev = ptr;
    }
    head = ptr;
}

int maxLikes(struct node *head) {
    int max = head->data;
    while(head!=NULL){
        if(head->data>max){
            max=head->data;
        }
        head=head->next;
    }
    return max;
}

void display(struct node *nodeptr) {
    while(nodeptr!=NULL){
        printf("\n%d",nodeptr->data);
        nodeptr = nodeptr->next;
    if(nodeptr!=NULL){
        printf("\n");
        }
    }
}

int main(){
    int choice, num, likes;
    char name[20];
    head = NULL;
    while(1){
    printf("\n--MENU--");
    printf("\n 1.To Add Facebook Friends");
    printf("\n 2.To Display Facebook Friends");
    printf("\n 3.To Display The Higest Number of Likes");
    printf("\n Enter your choice:");
    scanf("%d", &choice);
    switch(choice){
        case 1: printf("\nEnter The Name: ");
                scanf("%s",&name);
                printf("\nEnter The phone number: ");
                scanf("%d",&num);
                printf("\nEnter The likes: ");
                scanf("%d",&likes);
                insert(likes);
                break;
        case 2: 
        printf("\nFacebook friend list");
        display(head);
                break;
        case 3: printf("\n The friend with the highest number of likes is %s : %d",name, maxLikes(head));
                break;
        case 4: exit(0);
    }
    }
}
