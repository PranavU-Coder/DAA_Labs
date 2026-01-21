#include <stdio.h>
#include <math.h>

#define MAX 100

int prime_factorization(int n, int factors[], int powers[]) {
    int count = 0;
  
    if (n % 2 == 0) {
        factors[count] = 2;
        powers[count] = 0;
        while (n % 2 == 0) {
            powers[count]++;
            n = n / 2;
        }
        count++;
    }
    
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            factors[count] = i;
            powers[count] = 0;
            while (n % i == 0) {
                powers[count]++;
                n = n / i;
            }
            count++;
        }
    }
    
    if (n > 1) {
        factors[count] = n;
        powers[count] = 1;
        count++;
    }
    
    return count;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int gcd_middle_school(int m, int n) {
    int factors_m[MAX], powers_m[MAX];
    int factors_n[MAX], powers_n[MAX];
    int count_m, count_n;
    
    count_m = prime_factorization(m, factors_m, powers_m);
    count_n = prime_factorization(n, factors_n, powers_n);
    
    int gcd = 1;
    for (int i = 0; i < count_m; i++) {
        for (int j = 0; j < count_n; j++) {
            if (factors_m[i] == factors_n[j]) {
                int min_power = min(powers_m[i], powers_n[j]);
                for (int k = 0; k < min_power; k++) {
                    gcd *= factors_m[i];
                }
            }
        }
    }
    
    return gcd;
}

int main() {
    int m, n, result;
    
    printf("enter first number: ");
    scanf("%d", &m);
    printf("enter second number: ");
    scanf("%d", &n);
    
    result = gcd_middle_school(m, n);
    
    printf("\nGCD(%d, %d) = %d\n", m, n, result);
    
    return 0;
}
