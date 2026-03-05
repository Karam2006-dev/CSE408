#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
bool rotateString(char *s, char *goal){
    size_t len1 = strlen(s);
    size_t len2 = strlen(goal);
    if(len1 != len2) return false;
    char *temp = malloc(len1 * 2 + 1);
    if(!temp) return false;
    strcpy(temp, s);
    strcat(temp, s);
    bool found = (strstr(temp, goal) != NULL);
    free(temp);
    return found;
}
int main(){
    char s[] = "abcde";
    char goal[] = "cdeab";
    if(rotateString(s, goal)) printf("true");
    else printf("false");
    return 0;
}