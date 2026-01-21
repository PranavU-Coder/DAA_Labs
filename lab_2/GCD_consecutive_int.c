#include <stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int gcd_consecutive(int m, int n) {
    int t = min(m, n);
    
    while (t > 0) {
        if (m % t == 0 && n % t == 0) {
            return t;
        }
        t--;
    }
    
    return 1;
}

int main() {
    int m, n, result;
    
    printf("enter first number: ");
    scanf("%d", &m);
    printf("enter second number: ");
    scanf("%d", &n);

    result = gcd_consecutive(m, n);
    
    printf("\nGCD(%d, %d) = %d\n", m, n, result);
    
    return 0;
}
