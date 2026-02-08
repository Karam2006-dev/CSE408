#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void substring(char s[]){
    int n=strlen(s);
    int start=0,end=1;
    int maxlen=0;
    int maxstart=0;
    for(int i=0;i<n;i++){
        start=i;
        end=i;
        while(start>=0&&end<n&&s[start]==s[end]){
            if(end-start+1>maxlen){
                maxlen=end-start+1;
                maxstart=start;

            }
            start--;
            end++;
        }
        start=i;
        end=i+1;
        while(start>=0&&end<n&&s[start]==s[end]){
            if(end-start+1>maxlen){
                maxlen=end-start+1;
                maxstart=start;

            }
            start--;
            end++;
        }
    }
    for(int i=maxstart;i<maxstart+maxlen;i++){
        printf("%c",s[i]);
    }
    printf("\n");
}
int main(){
    char s[]="babad";
    substring(s);
    return 0;
}