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

void findIntersection(struct Node* h1, struct Node* h2){
    while(h1){
        struct Node* temp=h2;

        while(temp){
            if(h1->data==temp->data){
                printf("%d",h1->data);
                return;
            }
            temp=temp->next;
        }
        h1=h1->next;
    }

    printf("No Intersection");
}

int main(){
    int n,m;

    scanf("%d",&n);
    struct Node* head1=createList(n);

    scanf("%d",&m);
    struct Node* head2=createList(m);

    findIntersection(head1,head2);

    return 0;
}