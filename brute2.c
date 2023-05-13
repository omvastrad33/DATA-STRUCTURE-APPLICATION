//minimum value in an array//
#include <stdio.h>
#include <limits.h>

int main() {
    int arr[] = {10, 3, 8, 4, -2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    int min = INT_MAX;
    for(int i=0; i<n; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    printf("Minimum value in the array: %d\n", min);

    return 0;
}
