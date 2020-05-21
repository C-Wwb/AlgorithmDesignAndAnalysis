#include<bits/stdc++.h>
using namespace std;
int n,m,d;
int a1[100][100];//cij
int a2[100][100];//wij
int w=0;
int p=0;
int bestw=1000000;
int x[100];//记录所选部门
int x1[100];
void machine(int t){
    if(t>=n){
        if(w<bestw){
            bestw=w;
            for(int i=0;i<n;i++){
                x1[i]=x[i];
            }
        }
        return;
    }
    for(int i=0;i<m;i++){
        p += a1[t][i];
        w += a2[t][i];
        x[t] = i;
        if(p <= d && w <= bestw){
            machine(t+1);
        }
        p -= a1[t][i];
        w -= a2[t][i];
    }
}
int main()
{

    cin >> n >> m >> d;
    memset(x1,0,sizeof(x1));
    memset(x,0,sizeof(x));
    memset(a1,0,sizeof(a1));
    memset(a2,0,sizeof(a2));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a1[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a2[i][j];
        }
    }
    machine(0);
    cout << bestw << endl;
    for(int i = 0; i < n; i++){
        cout << x1[i] + 1 << " ";
    }
    return 0;
}