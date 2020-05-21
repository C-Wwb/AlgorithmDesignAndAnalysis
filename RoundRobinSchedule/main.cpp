#include <iostream>
#include<vector>
using namespace std;
/**
 * 一、实验要求：1）每个队伍必须与其他n-1个选手各比赛一次
 *         2）每个队伍一天只能比赛一次
 *         3）比赛队伍不能轮空
 *
 * 二、实验分析：1）将比赛设计为n行n-1列的二维表
 * （其中vec[0][0] == 2 代表和第1个选手在第1天比赛选手为2号选手）
 *         2）分治策略：将所有参赛的队伍分为两部分
 * （其中4个队伍（n = 2 ^ k）的比赛日程表由2个队伍（n = 2 ^ （k- 1））唯一决定）
 * 递归这样的分割直到剩下两个选手，比赛日程表由这样的分布策略逐步合并构建。
 *
 * 三、迭代过程：每次迭代的过程可以分为下面四个部分
 *         1）求左上角子表（n = 2 ^ （k- 1）个选手前半程的比赛日程）
 *         2）求左下角子表（剩余n = 2 ^ （k- 1）个选手的前半程比赛日程）
 * 对应关系为左上角子表中各对应元素加2 ^ （k- 1））
 *         3）求右上角子表（与左下角各对应元素相等）
 *         4）求右下角子表（与左上角各对应元素相等）
 *
 * @param team 循环比赛日程表
 */
void GameTable(vector<vector<int>> &team){
    if(team.empty())
    {
        return;
    }
    size_t s = team.size();
    int k = 0;
    s = s >> 1;
    while(s)
    {
        k++;
        s = s >> 1;
    }

    //初始化只有两个选手的日程安排（可看作最小单位）
    team[0][0] = 1;
    team[0][1] = 2;
    team[1][0] = 2;
    team[1][1] = 1;

    for(int i = 2; i <= k; i++)
    {
        int length = 0x1 << i;
        int half = length >> 1;
        //左下角的子表中项为左上角子表对应项加half=2^(i-1)
        for(int row = 0; row < half; row++)
        {
            for(int col = 0; col < half; col++)
            {
                team[row + half][col] = team[row][col] + half;
            }
        }

        //右上角的子表等于左下角子表
        for(int row = 0; row < half; row++)
        {
            for(int col = 0; col < half; col++)
            {
                team[row][col + half] = team[row + half][col];
            }
        }

        //右下角的子表等于左上角子表
        for(int row = 0; row < half; row++)
        {
            for(int col = 0; col < half; col++)
            {
                team[row + half][col + half] = team[row][col];
            }
        }
    }
}
/**
 *
 * @return 0
 */
int main(){
    cout << "There are 2^k contestants in the competition. "
            "\nPlease enter k (k>0) :" << endl;
    int k;
    do{
        cin >> k;
    }while(k < 0 || k > 31);//限制一个k的范围

    int s = 0x1 << k;
    vector<vector<int>> vec(s, vector<int>(s, 0));

    GameTable(vec);//生成表

    cout << "The team's round robin schedule is: " << endl;
    for(auto & i : vec){
        for(int j : i){
            cout << j << " | ";
        }
        cout << endl;
    }
    return 0;
}
/*
 * 此过程就是一个分部分填表再合并的过程
 * 因此其时间、空间复杂度为均为O(2^k * 2^k)
 */