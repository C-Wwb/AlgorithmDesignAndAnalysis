#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    const int N = 5;                     //物品个数
    const int V = 11;                    //背包体积
    int C[N + 1] = {1,2,5,6,7};  //第i个物品的体积（下标从1开始）
    int W[N + 1] = {1,6,18,22,28};   //第i个物品的价值
    int F[N + 1][V + 1] = { 0 };         //状态

    for (int i = 1; i <= N; i++)  //对于第i个物品
        for (int v = 0; v <= V; v++)
        {
            F[i][v] = F[i - 1][v];  //第i个不放
            if (v - C[i] >= 0 && F[i][v] < F[i - 1][v - C[i]] + W[i])  //如果比它大，再放第i个
                F[i][v] = F[i - 1][v - C[i]] + W[i];
        }

    cout << F[N][V] << endl;  //9

    return 0;
}