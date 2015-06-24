#include <stdio.h>

#define MOD 1000000007

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int T;
    int N;
    int i, j;
    scanf("%d", &T);
    for (i = 0; i < T; ++i){
        unsigned long long int sum = 0;
        unsigned long long int temp;
        scanf("%d", &N);
        for (j = 0; j < N; ++j){
            scanf("%llu", &temp);
            sum |= temp; 
        }
        /* deal with large number, (x * y) mod z = ((x mod z) * y) mod z */
        for (j = 0; j < N - 1; ++j){
            sum <<= 1; 
            sum %= MOD;
        }
        printf("%llu\n", sum);
    }
    return 0;
}

