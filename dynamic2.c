//Floyd-Warshall//
#include <stdio.h>

int main() {
    int r[4][4];

    printf("Enter the matrix elements:\n");
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            scanf("%d", &r[i][j]);
        }
    }

    for(int k = 0; k < 4; k++) {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                r[i][j] = r[i][j] || r[i][k] && r[k][j];
            }
        }
    }

    printf("Transitive closure of the matrix:\n");
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            printf("%d ", r[i][j]);
        }
        printf("\n");
    }

    return 0;
}
