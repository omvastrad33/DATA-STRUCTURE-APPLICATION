//Given an array of integers, find the pair of elements that have the smallest absolute difference//
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int minDiff = INT_MAX;
    int minDiffPair[2];

    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            int diff = abs(arr[i] - arr[j]);
            if(diff < minDiff) {
                minDiff = diff;
                minDiffPair[0] = arr[i];
                minDiffPair[1] = arr[j];
            }
        }
    }

    printf("Pair with smallest absolute difference: %d, %d\n", minDiffPair[0], minDiffPair[1]);

    return 0;
}
