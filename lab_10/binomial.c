#include <stdio.h>
#include<stdlib.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int main() {
    int n, k, i;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");
    scanf("%d", &k);
    if(n < 0 || k < 0) {
        printf("Invalid input");
        return -1;
    }
    int** dp = (int**)malloc(sizeof(int*) * (n+1));
    for(i = 0; i <= n; i++) {
        dp[i] = (int*)malloc(sizeof(int) * (k+1));
    }
    for(i = 0; i <= k; i++) {
        dp[0][i] = 1;
    }
    for(i = 1; i <= n; i++) {
        for(int j = 1; j <= MAX(i,k); j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    printf("The binomial coefficient is: %d", dp[n][k]);
    return 0;
}
