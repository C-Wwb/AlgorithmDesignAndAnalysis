#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
int a[1500];
int ser[50];//服务窗口的顾客等待时间
int sum[50];//服务窗口顾客等待时间的总和。
int main()
{
    int n,s;
    while(~scanf("%d %d",&n,&s))
    {
        for(int i = 0 ; i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        memset(ser,0,sizeof(ser));
        memset(sum,0,sizeof(sum));
        int i = 0;
        int j = 0;
        while(i < n)
        {
            ser[j] += a[i];
            sum[j] += ser[j];
            i++,j++;
            if(j == s)
                j = 0;
        }
        double t = 0;
        for(int i = 0; i < n; i++)
        {
            t += sum[i];
        }
        t /= n;
        printf("%0.3lf\n",t);
    }
    return 0;
}