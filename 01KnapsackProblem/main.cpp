#include<bits/stdc++.h>
using namespace std;
/**
 * 一、实验要求：1）n个物体；weight[i]为每个物体的重量；
 * value[i]为每个物体的价值；找到一个方案，使得在不超过背包最大重量的情况下
 * 获得物品的最大价值
 * 二、过程分析：
 *      1）求得问题的上下界，上界：背包中全部装入第一个物品；下界：贪心算法求得
 *      2）在根节点，没有任何物品装入背包，背包的重量和价值均为0
 *      3）之后每一层结点，都针对依次是否需要放物品进行讨论
 */
const int N = 100;
const int inf = 0x3f3f3f3f;
typedef long long ll;
class HeadNode{
public:
    double upper, prize, weight;//upper:节点上界，节点价值,节点重量
    int leve, x[N];//
};

stack<HeadNode> high;

double weight[N], value[N], cw, cp, c;
int n;
int cmp(int x,int y)
{
    return value[x] / weight[x] > value[y] / weight[y];
}
void add(double up, double cp, double cw, bool ch, int leve)//存放节点
{
    HeadNode be{};//生成一个空节点
    be.upper = up;
    be.prize = cp;
    be.weight = cw;
    be.leve = leve;
    if(leve <= n)
    {
        high.push(be);
    }
}
double MaxBound(int j)//更新上界
{
    double left = c-cw, b = cp;//left:剩余的容量,b:此时的价值
    while(j <= n && weight[j] <= left)//通过单位体积价值算出理想情况下的最优解
    {
        left -= weight[j];
        b += value[j];
        j++;
    }
    if(j <= n)
        b += value[j] / weight[j] * left;

    return b;
}
int os()
{
    int i = 1, cw = 0, cp = 0;//初始在第一层，当前重量为0，当前价值为0
    double bestp = 0, up = MaxBound(1);//bestp:最优解，up=MaxBound(1):在根节点时候的上界
    while(1)//(FIFO队列式分支限界法）此处可改为 priority_queue:优先队列，每次上界最大的在上面
    {

        double wt = cw + weight[i];//搜索左子树的可行解
        if(wt <= c)//更新
        {
            bestp = max(bestp, cp+value[i]);//更新可行解
            add(up, cp + value[i], cw+value[i], true, i + 1);//将此节点放入栈中
        }
        up = MaxBound(i + 1);//右节点不放
        if(up >= bestp)//右节点可能含有最优解
        {
            add(up, cp, cw, false, i + 1);
        }
        if(high.empty())
            return bestp;//当栈为空的时候，此时的bestp就是最优解
        HeadNode node = high.top();//把栈顶的点拿出来
        high.pop();
        cw = node.weight; cp = node.prize; up = node.upper;
        i = node.leve;
    }
}
int main()//测试函数
{

    cout << "Please enter the number of objects: " << endl;
    cin >> n;//n个物品，背包容量为c

    cout << "Please enter the backpack capacity: " << endl;
    cin >> c;

    cout << "Please enter the weight of the object: " << endl;
    for(int i = 1; i <= n; i++)
        cin >> weight[i];

    cout << "Please enter the value of the object: " << endl;
    for(int i = 1; i <= n; i++)
        cin >> value[i];
    sort(value+1,value+1+n,cmp);

    cout << "For optimal solution: " << endl;
    cout << os() <<endl;

}
/*
4 9
3 2 5 4
66 40 95 40

161

4 5
1 2 3 4
2 4 4 5

8

3 30
16 15 15
45 25 25

50
*/