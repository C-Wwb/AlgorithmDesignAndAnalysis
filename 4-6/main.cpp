#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,i,j,temp;
    printf("Please enter the number of customers waiting for service: \n");
    scanf("%d",&n);
    int* a = (int *)malloc(sizeof(int)* n);
    printf("Please enter the service time required by each customer: \n");
    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    int sum = 0;
    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++){
            if(a[i] > a[j]){
                temp = a[i];a[i] = a[j];a[j] = temp;
            }
        }
    }

    for(i = 1; i < n; i++){//每个位置累加前面到自己
        a[i] += a[i-1];
    }
    for(j = 0; j < n; j++)//加起来
        sum += a[j];
    printf("The minimum average waiting time is %.2f\n",sum*1.0/n);
    return 0;
}