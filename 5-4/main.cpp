#include<bits/stdc++.h>
using namespace std;
int n;
int P[100][100];
int Q[100][100];
int X[100];
int BEST[100];
int answer = 0;
void swap(int &a,int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void update(){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += P[i][X[i]] * Q[X[i]][i];
    }
    if(sum > answer){
        answer = sum;
        for(int i = 1;i <= n; i++){
            BEST[i] = X[i];
        }
    }
}
void backtrace(int level){
    if(level > n){
        update();

    }
    else{
        for(int i = level; i <= n; i++){
            swap(X[level],X[i]);
            backtrace(level+1);
            swap(X[level],X[i]);
        }
    }
}
int main()
{

    cin >> n;
    memset(P,0,sizeof(P));
    memset(Q,0,sizeof(Q));
    memset(BEST,0,sizeof(BEST));
    memset(X,0,sizeof(X));
    for(int i = 1;i <= n;i++){
        for(int j = 1; j <= n; j++){
            cin >> P[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> Q[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        X[i] = i;
    }
    backtrace(1);
    cout << answer << endl;
    for(int i = 1; i <= n; i++){
        cout << BEST[i] << " ";
    }
    return 0;
}