//MINIMUM COST OF ROPES PROB//
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Enter the number of ropes: ");
    scanf("%d", &n);
    int ropes[n];
    printf("Enter the lengths of the ropes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &ropes[i]);
    }
    int result = min_cost_ropes(ropes, n);
    printf("The minimum cost of ropes is: %d\n", result);
    return 0;
}


int min_cost_ropes(int ropes[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (ropes[j] > ropes[j+1]) {
                int temp = ropes[j];
                ropes[j] = ropes[j+1];
                ropes[j+1] = temp;
            }
        }
    }
    int total_cost = 0;
    while (n > 1) {
        int rope1 = ropes[0];
        int rope2 = ropes[1];
        int cost = rope1 + rope2;
        total_cost += cost;
        ropes[0] = cost;
        for (int i = 1; i < n-1; i++) {
            ropes[i] = ropes[i+1];
        }
        n--;
    }
    return total_cost;
}

