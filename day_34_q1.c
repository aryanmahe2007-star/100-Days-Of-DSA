#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

int pop(){
    if(top == NULL){
        printf("Stack Underflow\n");
        return 0;
    }

    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main(){

    char expr[100];
    fgets(expr, sizeof(expr), stdin);

    char *token = strtok(expr, " ");

    while(token != NULL){

        if(isdigit(token[0])){
            push(atoi(token));
        }
        else{
            int b = pop();
            int a = pop();
            int result;

            switch(token[0]){
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(result);
        }

        token = strtok(NULL, " ");
    }

    printf("%d", pop());

    return 0;
}