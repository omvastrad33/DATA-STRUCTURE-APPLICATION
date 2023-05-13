//all possible paths from the top-left corner (0, 0) to the bottom-right corner (m-1, n-1) of an m x n matrix//
#include <stdio.h>
int main()
{
    int m = 3, n = 3;
    int path[m + n - 1];
    printf("All possible paths from (0, 0) to (%d, %d) in a %d x %d matrix:\n", m-1, n-1, m, n);
    printAllPaths(m, n, 0, 0, path, 0);

    return 0;
}

void printAllPaths(int m, int n, int i, int j, int path[], int idx)
{

    if (i == m - 1 && j == n - 1) {
        for (int k = 0; k < idx; k++) {
            printf("%d ", path[k]);
        }
        printf("\n");
        return;
    }

    if (j + 1 < n) {
        path[idx] = (i * n) + (j + 1) + 1;
        printAllPaths(m, n, i, j + 1, path, idx + 1);
    }


    if (i + 1 < m) {
        path[idx] = ((i + 1) * n) + j + 1;
        printAllPaths(m, n, i + 1, j, path, idx + 1);
    }
}


