#include<assert.h>
#include<stdio.h>

int length_of_last_word(char *s){
    int count = 0;
    int length_of_last_word = 0;
    while(*s != '\0'){
        if(*s == ' ')
            count = 0;
        else
            count++;
        if(count != 0)
            length_of_last_word = count;
        s++;
    }
    return length_of_last_word;
}

main(){
    char *str1 = "hello";
    assert(length_of_last_word(str1) == 5);
    char *str2 = " ";
    assert(length_of_last_word(str2) == 0);
    char *str3 = "hello world ";
    assert(length_of_last_word(str3) == 5);
}
