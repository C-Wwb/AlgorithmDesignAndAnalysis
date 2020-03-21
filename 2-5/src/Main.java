import java.util.Scanner;

public class Main
{
    private static char[] strToChar = new char[50];
    private static int number;
    private static String inputStr;
    private static int total;
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        while(true)
        {
            //restore total
            total = 0;
            System.out.println("Please input the length of string: ");
            number = input.nextInt();

            System.out.println("Please input a string: ");
            inputStr = input.next();

            strToChar = inputStr.toCharArray();
            permute(strToChar, 0, number - 1);

            System.out.println("There are "+total+" different permutations!");
            break;
        }
    }
    private static void permute(char[] charList, int p, int o)//重新排列，改变次序
    {
        int count = 0;
        if(p == o)
        {
            total++;
            for(int i = 0; i <= o; i++)
            {
                System.out.print(charList[i]);
                count++;
                if(count % 4 == 0)
                {
                    System.out.println();
                }
            }
            return;
        }
        for(int i = p; i <= o; i++)
        {
            if(duplicate(charList, p, i))
            {
                swap(charList, p, i);
                permute(charList, (p + 1), o);
                swap(charList, p, i);
            }
        }
    }
    private static boolean duplicate(char[] charList, int p, int i)
    {
        if(i > p)
        {
            for(int j = p; j < i; j++)
                if(charList[j] == charList[i])
                    return false;
        }

        return true;
    }
    private static void swap(char[] charList, int p, int i)
    {
        char temp;
        temp = charList[p];
        charList[p] = charList[i];
        charList[i] = temp;
    }
}