//"minimum coin change"//
#include <stdio.h>
int main()
{
    int coins[] = {1, 5, 10, 25};
    int n = sizeof(coins) / sizeof(coins[0]);

    int value = 67;

    printf("Minimum number of coins required to make %d is %d\n", value, minCoins(coins, n, value));

    return 0;
}

int minCoins(int coins[], int n, int value)
{
    int count = 0;

    for (int i = n - 1; i >= 0; i--) {

        while (value >= coins[i]) {
            value -= coins[i];
            count++;
        }
    }

    return count;
}

