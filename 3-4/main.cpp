/*#include<iostream>
#include <c++/cstring>

#define N 10001
using namespace std;
int a[N]={0};
int len=1;
void multiply(int n){
    int i;
    for(i=0;i<len && i<N;++i){
        a[i] *= n;
    }
    for(i=0;i<len && i<N;++i){
        if(a[i]>=10){
            a[i+1] += a[i]/10;
            a[i] %= 10;
        }
    }
    while(a[len]){
        ++len;
        a[len] += a[len-1]/10;
        a[len-1] %= 10;
    }
}

void divide(int n){
    for(int i=len-1;i;--i){
        a[i-1] += (a[i]%n)*10;
        a[i] /= n;
    }
    a[0] /= n;
    while(a[len-1]==0){
        --len;
    }
}
void print(){
    int i=len-1;
    while(i>=0){
        printf("%d",a[i--]);
    }
}
void C(int n,int m){
    if(n-m<m){
        m = n-m;
    }
    for(int i=0;i<m;++i){
        multiply(n--);
    }
    while(m){
        divide(m--);
    }
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        memset(a,0,N);
        a[0] = 1;
        C(2*n,n);
        divide(n+1);
        print();
        printf("\n");
    }
}*/
#include<iostream>
using namespace std;
int main()
{
    int i,j,n;
    __int64 ans[30]={1,1,0};
    for(i = 2; i <= 29; i++)
    {
        for(j = 1; j <= i-1; j++)
            ans[i] += ans[j] * ans[i-j];
    }
    printf("Please enter the number: \n");
    while(scanf("%d",&n) != EOF)
    {
        printf("%I64d\n",ans[n]);
    }
}