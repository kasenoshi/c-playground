#include <stdio.h>
#define INT_MIN -2147483648
#define INT_MAX 2147483647

int myAtoi(char* str) {
    long long ans = 0;
    char minus = -1;
    while(*str == ' '|| *str == '\t' || *str == '\n')
        str++;
    while(*str != '\0'){
        if (*str == '+' && minus == -1){
            minus = 0;
            str++;
            continue;
        }
        else if(*str == '-' && minus == -1){
            minus = 1;
            str++;
            continue;
        }
        else if(*str == '\"'){
            str++;
            continue;
        }
        else if(*str < '0' || *str > '9'){
            if (ans != 0)
                break;
            break;
        }
        ans = 10 * ans + (long long)(*str - '0');
        if (minus == 1){
            if(-ans < INT_MIN){
                ans = INT_MIN;
                minus = 0;
                break;
            }
        }
        else{
            if(ans > INT_MAX){
                ans = INT_MAX;
                break;
            }
        }
        str++;
    }
    if (minus == 1){
        ans = -ans;
    }
    return (int)ans;
}
main(){
    printf("%d", myAtoi("\"9223372036854775809\""));
}
