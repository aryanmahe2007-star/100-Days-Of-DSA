#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createList(int n){
    struct Node *head=NULL,*temp=NULL,*newNode;

    for(int i=0;i<n;i++){
        newNode=(struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&newNode->data);
        newNode->next=NULL;

        if(head==NULL){
            head=temp=newNode;
        }
        else{
            temp->next=newNode;
            temp=newNode;
        }
    }
    return head;
}

void rotateRight(struct Node* head,int k){

    struct Node *temp=head;
    int n=1;

    while(temp->next){
        temp=temp->next;
        n++;
    }

    k=k%n;

    if(k==0){
        temp=head;
        while(temp){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        return;
    }

    temp->next=head;   // make circular

    int steps=n-k;
    temp=head;

    for(int i=1;i<steps;i++)
        temp=temp->next;

    struct Node* newHead=temp->next;
    temp->next=NULL;

    temp=newHead;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    int n,k;

    scanf("%d",&n);
    struct Node* head=createList(n);

    scanf("%d",&k);

    rotateRight(head,k);

    return 0;
}