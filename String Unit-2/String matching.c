#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
bool rotateString(char *s, char *goal){
    int len1 = strlen(s);
    int len2 = strlen(goal);
    if(len1 != len2) return false;
    char *temp = (char*)malloc(sizeof(char)*(len1*2+1));
    strcpy(temp, s);
    strcat(temp, s);
    if(strstr(temp, goal)!=NULL) return true;
    return false;
}
int main(){
    int s="abcde";
    int goal="cdeab";
    if(rotateString(s, goal)) printf("true");
    else printf("false");
}