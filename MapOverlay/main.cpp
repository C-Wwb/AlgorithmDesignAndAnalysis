#include<cstdio>
#include<cstring>
#include <c++/cstdlib>
#include <c++/iostream>
/**
 * 一、实验要求：m种颜色各地图（把每一块区域收缩为定点）着色，使得每个顶点一种颜色，且相邻定点颜色不同
 * 二、实验思路：对当前的第i个顶点着色
 *      1）如果已经求得一组解，输出方案并返回
 *      2）否则，依次对定点i着色
 *      3）判定，若顶点i的着色与其他定点无冲突，则继续为定点i+1着色
 *      4）若均失败，回溯，尝试下一种颜色
 */
using namespace std;
#define N 100
int map[N][N],color[N], finished, types, count;//color数组用来记录已完成顶点的着色情况
int ok(int cur) {
    int i;
    for(i = 1; i < cur; i++)
        if(map[cur][i] == 1 && color[cur] == color[i])
            return 0;
    return 1;
}
void graphcolor(int cur) {
    int i;
    if(cur > finished) {
        for(i = 1; i <= finished; i++)
            cout << color[i] << " ";
        cout << endl;
        count++;
        return;
    }

    for(i = 1; i <= types; i++) {
        color[cur] = i;
        if(ok(cur) == 1)
            graphcolor(cur + 1);
    }
}
int main() {
    int i, j, k, a, b;
    cin >> finished >> k >> types;
    memset(map,0,sizeof(map));
    for(i=1; i <= k; i++){//初始化地图
        cin >> a >> b;
        map[a][b] = map[b][a] = 1;
    }
    count = 0;
    graphcolor(1);
    cout << count;
    system("pause");
    return 0;
}
/*
 * text
 * 5 8 4
 * 2 1
   2 3
   2 4
   2 5
   1 3
   3 4
   4 5
   1 4
 */