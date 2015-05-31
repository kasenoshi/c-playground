#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int my_getline(void){
    int i;
    char c;
    extern char line[];
    for(i = 0; i < MAXLINE && ((c = getchar()) != EOF) && c != '\n'; ++i){
        line[i] = c;
    }
    if (c == '\n'){
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}
void copy(void){
    extern char line[];
    extern char longest[];
    int i = 0;
    while((longest[i] = line[i]) != '\0')
        ++i;
}

main(){
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while ((len = my_getline()) > 0){
        if (len > max){
            max = len;
            copy();
        }
    }
    if (max > 0)
        printf("%s", longest);
}

