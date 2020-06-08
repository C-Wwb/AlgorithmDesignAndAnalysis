
#include <iostream>
#include <vector>
using namespace std;
/**
 * 一、实验说明
 *  1、使用dijkstra贪心算法寻找最短路径，以连接矩阵的形式来表示该图
 *  2、基本思路：对图G(V,E)设置集合S，存放已被访问的顶点，
 然后每次从集合V-S中选择与起点s的最短距离最小的一个顶点（记为u），
 访问并加入集合S。后令u为中介点，优化起点s与所有从u能够到达的顶点v之间的最短距离。
 这样的操作执行n次（n为顶点个数），直到集合S已经包含所有顶点。
    3、时间复杂度分析：主要是外层的循环O(V)（V就是顶点个数n）
 与内层循环（寻找最小的d[u]需要O(V)、枚举需要O(V)产生的），
 总的时间复杂度为O(V*(V+V))=O(V^2)
 * 二、可行性分析：该问题所使用的的贪心算法可以得到最优解，
 因为有向图的最短路径问题，具有贪心选择性质和最优子结构性质。
      证明：1、贪心选择性：首先贪心选择开始，原问题变为规模更小的子问题，
 之后用数学归纳法证明，在算法执行中，任意一点的集合S，对每个路径是最短的s-u路径，
 |S|=1 时， S={s},d(s)=0 显然成立；假设|S|=k时，命题成立；|S|=k+1时，
 s要到达v，必须首先离开S，然后到达y，最后y到达v，P`v = P`y + Lyv
 且根据dijkstra可知P`y>=Pv,而且边的权值非负，所以Pv是s-v所有路径中的最短
           2、最优子结构：因为该问题的最优解包含其子问题的最优解，该性质描述为：
 如果S(i,j)={Vi....Vk..Vs...Vj}是从顶点i到j的最短路径，
 k和s是这条路径上的一个中间顶点，那么S(k,s)必定是从k到s的最短路径。
 下面证明该性质的正确性。
 假设S(i,j)={Vi....Vk..Vs...Vj}是从顶点i到j的最短路径，
 则有S(i,j)=S(i,k)+S(k,s)+S(s,j)。而S(k,s)不是从k到s的最短距离，
 那么必定存在另一条从k到s的最短路径S'(k,s)，那么S'(i,j)=S(i,k)+S'(k,s)+S(s,j)<S(i,j)，
 则与S(i,j)是从i到j的最短路径相矛盾。因此该性质得证最优子结构。
 * 三、算法伪代码
 *
//G为图；数组d为源点到达各点的最短路径长度，s为起点
Dijkstra(G, d[], s)
{
     初始化;
     for(循环n次)
     {
          u = 使d[u]最小的还未被访问的顶点的标号;
          记u已被访问;
          for(从u出发能到达的所有顶点v)
          {
               if(v未被访问 && 以u为中介点使s到顶点v的最短距离d[v]更优)
               {
                    优化d[v];
               }
          }
     }
}
 */
const int INF = 1000000000;

/*Dijkstra算法解决的是单源最短路径问题，即给定图G(V,E)和起点s(起点又称为源点),
求从起点s到达其它顶点的最短距离，并将最短距离存储在矩阵d中*/
void Dijkstra(int n, int s, vector<vector<int>> G, vector<bool>& vis, vector<int>& d, vector<int>& pre)
{
    /*
    param
    n：           顶点个数
    s：           源点
    G：           图的邻接矩阵
    vis：         标记顶点是否已被访问
    d：           存储源点s到达其它顶点的最短距离
    pre：         存储从起点s到达顶点v的最短路径上v的前一个顶点 （新添加）
    */
    fill(d.begin(), d.end(), INF);                         //初始化最短距离矩阵，全部为INF

    for (int i = 0; i < n; ++i)                            //新添加
        pre[i] = i;

    d[s] = 0;                                              //起点s到达自身的距离为0
    for (int i = 0; i < n; ++i)
    {
        int u = -1;                                     //找到d[u]最小的u
        int MIN = INF;                                  //记录最小的d[u]
        for (int j = 0; j < n; ++j)                     //开始寻找最小的d[u]
        {
            if (vis[j] == false && d[j] < MIN)
            {
                u = j;
                MIN = d[j];
            }
        }
        //找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
        if (u == -1)
            return;
        vis[u] = true;                                  //标记u已被访问
        for (int v = 0; v < n; ++v)
        {
            //遍历所有顶点，如果v未被访问&&u能够到达v&&以u为中介点可以使d[v]更优
            if (vis[v] == false && d[u] + G[u][v] < d[v]) {
                d[v] = d[u] + G[u][v];             //更新d[v]
                pre[v] = u;                        //记录v的前驱顶点为u（新添加）
            }
        }
    }
}

//输出从起点s到顶点v的最短路径
void DFSPrint(int s, int v, vector<int> pre)
{
    if (v == s) {
        cout << s << " ";
        return;
    }
    DFSPrint(s, pre[v], pre);
    cout << v << " ";
}

int main()
{
    int n = 11;
    vector<vector<int>> G = { {0,5,3,INF,INF,INF,INF,INF,INF,INF,INF},
                              {INF,0,INF,1,6,3,INF,INF,INF,INF,INF},
                              {INF,INF,0,INF,8,INF,4,INF,INF,INF,INF},
                              {INF,INF,INF,0,INF,INF,INF,5,5,INF,INF},
                              {INF,INF,INF,INF,0,INF,INF,6,INF,INF,INF},
                              {INF,INF,INF,INF,INF,0,INF,INF,INF,8,INF},
                              {INF,INF,INF,INF,INF,INF,0,INF,INF,3,INF},
                              {INF,INF,INF,INF,INF,INF,INF,0,INF,INF,3},
                              {INF,INF,INF,INF,INF,INF,INF,INF,0,INF,4},
                              {INF,INF,INF,INF,INF,INF,INF,INF,INF,0,3},
                              {INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,0}};
    vector<bool> vis(n);
    vector<int> d(n);
    vector<int> pre(n);

    Dijkstra(n,0,G,vis,d,pre);
    for (auto x : d)
        cout << x << " ";
    cout << endl;

    //输出从起点s到顶点v的最短路径
    DFSPrint(0, 10, pre);
}