#include<stdio.h>

void push(int item);
void dfs();
int pop();

int vis[50], stack[50], top = -1;
int a[50][50];
int n, s;

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the starting node: ");
    scanf("%d", &s);
    dfs();
    return 0;
}

void dfs() {
    vis[s] = 1;
    printf("%d ", s);
    push(s);
    while (top != -1) {
        int node = pop();
        for(int i = 1; i <= n; i++) {
            if(a[node][i] != 0 && vis[i] == 0) {
                vis[i] = 1;
                printf("%d ", i);
                push(i);
            }
        }
    }
}

void push(int item) {
    if(top == 50 - 1) {
        printf("Stack overflow ");
        return;
    }
   stack[++top] = item;
}

int pop() {
    if(top == -1) {
        return 0;
    }
    int k = stack[top--];
    return k;
}
