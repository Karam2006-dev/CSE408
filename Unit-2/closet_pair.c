#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int x;// global variable for comparator function

int compare(const void *a,const void *b){
    int valA=*(const int *)a;
    int valB=*(const int *)b;
    int diff1=abs(valA-x);
    int diff2=abs(valB-x);
    if(diff1==diff2){
        return valA-valB;
    }
    return diff1-diff2;
} 
void printKcloset(int arr[],int n,int k,int x,int result[]){
    qsort(arr,n,sizeof(int),compare);
    for(int i=0;i<k;i++){
        result[i]=arr[i];
    }
}

int main(){
    int arr[]={12,16,22,30,35,39,42,45,48,52};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=4;
    int x=35;
    int result[k];
    printKcloset(arr,n,k,x,result);
    for(int i=0;i<k;i++){
        printf("%d ",result[i]);
    }
    return 0;
}