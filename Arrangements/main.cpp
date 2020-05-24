
#include<stdio.h>
#define M 11
#define MAX 2000
/**
 * 一、实验问题：有n个活动集合，每个活动分别有开始和结束时间，
 * 求出最大相容子集合
 * 二、实验思路：把所有问题看成时间片段，放在时间轴上，从开始段进行观察，
 * 发现既然活动的时间排列是线性的，就应该选择选最早开始的活动
 * （和相对最早开始的活动，即相对于剩下活动开始最早的活动），
 * 即选用贪心算法
 * 三、实现思路：分别定义活动的起始和终止时间数组，首先选择开始时间最早的活动，
 * 之后选择距离前一个活动结束时间最近的活动，以此类推，得到子集合的活动组合
 *
 * @param num 共有多少个活动
 * @param start 各个活动的开始时间集合
 * @param finish 各个活动的结束时间集合
 */
void select(int num,int start[],int finish[]){

    int preStart = 0;
    int preFinal = MAX;//保证是无限大即可
    int i;
    int temp;
    int OK = 1;
    int sel[M];//用来储存相容的活动编号
    int selNum = 0;


    while(OK){
        OK = 0;
        for(i = 0; i < M; i++){

            if(finish[i] < preFinal&&start[i] >= preStart){//寻找开始时间合适地情况下结束时间最早者
                preFinal = finish[i];
                temp = i;
                OK = 1;
                printf("%d to %d\n", start[i], finish[i]);
            }
        }

        if(preFinal != MAX){  //变量的重新赋值
            sel[selNum++] = temp;
            preStart = finish[temp];
            preFinal = MAX;
        }
    }
    printf("%d",selNum);//相容数量
}

int main(){
    int start[]={1,3,0,5,3,5,6,8,8,2,12};
    int finish[]={4,5,6,7,8,9,10,11,12,13,14};
    select(M,start,finish);
}
/*
 * start：1 3 0 5 3 5 6 8 8 2 12
 * finish：4 5 6 7 8 9 10 11 12 13 14
 */