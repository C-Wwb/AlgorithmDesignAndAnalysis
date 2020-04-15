import java.util.Scanner;

public class Main {
    public static int numberOfStone;
    public static int[][] min = new int[100][100];
    public static int[][] max = new int[100][100];

    public static void main(String[] args) {
        int[] stone = new int[50];
        Scanner input = new Scanner(System.in);

        for(int i = 0; i < 100; i++){               //初始化min矩阵和max矩阵
            for(int j = 0; j < 100; j++){
                min[i][j] = 0;
                max[i][j] = 0;
            }
        }
        System.out.print("输入n堆石子：");
        numberOfStone = input.nextInt();
        System.out.print("输入每堆石子的个数：");
        for(int i = 0; i < numberOfStone; i++)
            stone[i] = input.nextInt();
        System.out.println("最小得分为：" + Main.getMin(stone));
        System.out.println("最大得分为：" + Main.getMax(stone));
        input.close();
    }
    public static int Sum(int a, int b, int[] stone){
        int sum = 0;
        for(int i = a-1; i < (a-1)+b; i++)
            sum += stone[i % numberOfStone];
        return sum;
    }
    //获得最大得分
    public static int getMax(int[] stone){
        int flag, max;
        for(int j = 2; j <= numberOfStone; j++){
            for(int i = 1; i <= numberOfStone; i++){
                max = 0;
                for(int k = j-1; k > 0; k--){
                    if((i+k) <= numberOfStone)
                        flag = Main.max[i][k] + Main.max[i+k][j-k] + Main.Sum(i, j, stone);
                    else
                        flag = Main.max[i][k] + Main.max[(i+k) % numberOfStone][j-k] + Main.Sum(i, j, stone);
                    if(flag > max)
                        max = flag;
                }
                Main.max[i][j] = max;
            }
        }
        max = 0;
        for(int i = 1; i <= numberOfStone; i++){
            flag = Main.max[i][numberOfStone];
            if(flag > max)
                max = flag;
        }
        return max;
    }
    //获得最小得分
    public static int getMin(int[] stone){
        int flag, min;
        for(int j = 2; j <= numberOfStone; j++){
            for(int i = 1; i <= numberOfStone; i++){
                min = 1000;
                for(int k = j-1; k > 0; k--){
                    if((i+k) <= numberOfStone)
                        flag = Main.min[i][k] + Main.min[i+k][j-k] + Main.Sum(i, j, stone);
                    else
                        flag = Main.min[i][k] + Main.min[(i+k) % numberOfStone][j-k] + Main.Sum(i, j, stone);
                    if(flag < min)
                        min = flag;
                }
                Main.min[i][j] = min;
            }
        }
        min = 1000;
        for(int i = 1; i <= numberOfStone;i++){
            flag = Main.min[i][numberOfStone];
            if(flag < min)
                min = flag;
        }
        return min;
    }
}