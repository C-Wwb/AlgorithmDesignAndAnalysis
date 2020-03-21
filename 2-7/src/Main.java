import java.util.Scanner;
public class Main
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        System.out.println("Please enter number: ");
        int number = input.nextInt();
        split(number);
    }
    public static void split(int number)
    {
        int count = 0;
        for(int i = 1; i <= number; i++)
        {
            count += DG(number, i);
        }
        System.out.println("总划分数：" + count);
    }
    public static int DG(int number, int i)
    {
        if(i > number)
        {
            DG(number,number);
        }
        if(number == 1 || i == 1 || number == i)
        {
            return 1;
        }
        else
        {
            return DG(number - 1,i - 1)+ i * DG((number - 1), i);
        }
    }
}
