#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val){
    stack[++top] = val;
}

void pop(){
    if(top != -1)
        top--;
}

int main(){
    int n, m, x;

    scanf("%d", &n);

    // push elements
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        push(x);
    }

    scanf("%d", &m);

    // pop m elements
    for(int i = 0; i < m; i++){
        pop();
    }

    // display remaining stack from top to bottom
    for(int i = top; i >= 0; i--){
        printf("%d ", stack[i]);
    }

    return 0;
}