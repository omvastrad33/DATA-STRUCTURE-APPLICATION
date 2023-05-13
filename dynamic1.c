//minimum number of perfect squares required to sum up to a target number://
#include <stdio.h>
#include <limits.h>
#include <math.h>

int main() {
    int n, k;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &k);
    printf("Minimum number of squares to sum up to %d: %d\n", k, min_squares_sum(arr, n, k));
    return 0;
}


int min_squares_sum(int arr[], int n, int k) {
    int dp[k+1];
    dp[0] = 0;
    for (int i = 1; i <= k; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (arr[j] <= i) {
                dp[i] = fmin(dp[i], dp[i - arr[j]] + 1);
            }
        }
    }
    return dp[k];
}

