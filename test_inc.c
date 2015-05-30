#include <stdio.h>

void a(){
    int i = 2147483647;
    while(i != 0){
        --i;
    }
}
void b(){
    int i = 2147483647;
    while(i != 0){
        i--;
    }
}
main(){
    a();
    b();
}
