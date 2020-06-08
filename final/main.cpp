#include<stdlib.h>
#include<stdio.h>
#define x 9999
#define max 9999
int data[11][11];
int dist[10];//记录最短路径为多少
int path[11];//记录最短路径
int kmin(int,int);
void fpath(int a[][11]);
int froute(int a[][11]);
/**
 * 一、实验说明：
 *  1、使用viterbi动态规划寻找最短路径,以连接矩阵的形式来表示该图。
 *  2、基本思路：把大得问题细分为许多小的问题，基于每一步的结果，再去寻找
  下一步的策略，通过每一步走过之后的局部最优解进而得到全局最优解。
 *  3、问题分析：从A到E的全局最优解必定经过局部最优解，问题规模逐渐缩小，
  所以从A点出发，逐层遍历来寻找各层之间的最短距离。
 *  4、证明该问题具有最优子结构（假设论证）：
  设Pae是从A点出发到E点的最短路径，V是路径内部异于A和E的任意一点，
  如果存在另一Pae`是更短的路径，与原AE点无关，那么利用复制粘贴法将Pae替换，
  这样就存在新的AE点组成最短路径，与假设矛盾。
  如果存在另一Pae`是更短的路径，与原AE点有关，那么不能利用复制粘贴法
 * 二、实验过程（证明子问题的重叠性）
 *  1、从A点出发，计算出A点到B点的各个距离，因为只有一步，所以这些距离都是
  A点到各B点的最短距离。（d（S,A1）,d（S,A2）,d（S,A3）,d（S,A4））
 *  2、从各个B点出发，计算出各个B点到各个C点的距离，则供需再计算五组数据
  （d（S,B2）=d（S,Ai）+d（Ai,B2）其中i为各节点数量）
 *  3、从上一步中获得的五组数据，只保留B的数量组，也就是两组最短数据，
  将这样的保留方式一直延续到最后一组状态，使用这种维特比算法，大幅度减少计算量
 * 三、时间复杂度计算
 假设整个网格的宽度为D，网格长度为N，使用维特比算法的时间复杂度为O（ND2）
 */
int main()
{
    int i,m;
    int a[11][11]=
            {
                    {x,5,3,x,x,x,x,x,x,x,x},
                    {x,x,x,1,6,3,x,x,x,x,x},
                    {x,x,x,x,8,x,4,x,x,x,x},
                    {x,x,x,x,x,x,x,5,5,x,x},
                    {x,x,x,x,x,x,x,6,x,x,x},
                    {x,x,x,x,x,x,x,x,x,8,x},
                    {x,x,x,x,x,x,x,x,x,3,x},
                    {x,x,x,x,x,x,x,x,x,x,3},
                    {x,x,x,x,x,x,x,x,x,x,4},
                    {x,x,x,x,x,x,x,x,x,x,3},
                    {x,x,x,x,x,x,x,x,x,x,x}
            };
    fpath(a);
    printf("The shortest path size is: %d\n",dist[10]);

    m = froute(a);
    for(i = m - 1; i >= 0; i--)
        printf("Shortest path through: %d\n", path[i]);
}
void fpath(int a[][11])
{
    int i, j, k;
    dist[0] = 0;
    for(i = 1; i < 11; i++)
    {
        k = max;
        for(j = 0; j < i; j++)
        {
            if(a[j][i] != x)
                if((dist[j] + a[j][i]) < k)
                    k = dist[j] + a[j][i];
        }
        dist[i] = k;
    }
}
int froute(int a[][11])
{
    int j, b, k = 1, i = 10;
    path[0] = 11;
    while(i > 0)
    {
        for(j = i - 1; j >= 0; j--)
        {
            if(a[j][i] != x)
            {
                b = dist[i] - a[j][i];
                if(b == dist[j])
                {
                    path[k++] = j + 1;
                    i = j;
                    break;
                }
            }
        }
    }
    return k;
}