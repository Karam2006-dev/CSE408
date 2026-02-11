#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define d 256
#define q 101
void rabinKarp(char *txt,char *pat){
    int M=strlen(pat);
    int N=strlen(txt);
    int p=0;
    int t=0;
    for(int i=0;i<M;i++){
        p=(d*p+pat[i])%q;
        t=(d*t+txt[i])%q;
    }
    int h=1;
    for(int i=0;i<M-1;i++){
        h=(h*d)%q;
    }
    for(int i=0;i<=N-M;i++){
        if(p==t){
            int j;
            for(j=0;j<M;j++){
                if(txt[i+j]!=pat[j]){
                    break;
                }
            }
            if(j==M){
                printf("Pattern found at index %d\n",i);
            }
        }
        if(i<N-M){
            t=(d*(t-txt[i]*h)+txt[i+M])%q;
            if(t<0){
                t=t+q;
            }
        }
    }
}
int main(){
    char txt[]="ABABDABACDABABCABAB";
    char pat[]="ABABCABAB";
    rabinKarp(txt,pat);
    return 0;
}