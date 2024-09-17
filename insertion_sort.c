#include<stdio.h>
int main(){
    int a[5],i,j,k,t;
    printf("enter the number in array:\n");
    for(i=0;i<5;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<5;i++){
        for(j=0;j<i;j++){
            if(a[i]<a[j]){
               t = a[j];
               a[j]=a[i];
               a[i]=t; 
               for(k=i;k>j;k--){
                a[k]=a[k-1];
               }
               a[k+1]=t;
            }
        }
    }
    for(i=0;i<5;i++){
        printf("%d ",a[i]);
    }
    return 0;
}