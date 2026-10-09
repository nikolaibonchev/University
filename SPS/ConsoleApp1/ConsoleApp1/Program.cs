class Program
{
    static int Main()
    {   /* задача 1
        Console.WriteLine("  ******   ******  ");
        Console.WriteLine(" *      * *       *");
        Console.WriteLine("  *              * ");
        Console.WriteLine(" *       *        *");
        Console.WriteLine("   *            *  ");
        Console.WriteLine("    *          *   ");
        Console.WriteLine("     *        *    ");
        Console.WriteLine("      *      *     ");
        Console.WriteLine("       *    *      ");
        Console.WriteLine("        *  *       ");
        Console.WriteLine("         *        ");*/

        /* задача 2
        Console.WriteLine("Enter num 1:");
        int n1 = Int32.Parse(Console.ReadLine());
        Console.WriteLine("Enter num 2:");
        int n2 = Int32.Parse(Console.ReadLine());

        int diff = 0;

        if (n1 <= n2)
        {
            diff = n2 - n1;
        }
        else if (n1 >= n2)
        {
            diff = n1 - n2;
        }

        Console.WriteLine("The difference is: " + diff);*/

        /* задача 3
        int[] arr = { 1, 2, 3, 0, 5, 6, 7, 8, 9, 10 };
        
        for(int i = 0; i < 10; i++)
        {
            if(arr[i] == 0 && arr[i+1] == 0)
            {
                Console.WriteLine("It has two 0s one after another");
                break;
            }
        }*/

        int[] arr = { 1, 2, 3, 20, 1, 1, 1, 1, 1, 40 };
        int sum = 0;
        bool isBetween = false;

        for (int i = 0; i < 10; i++)
        {
            if (arr[i] == 40) isBetween = true;

            if (isBetween)
            {
                sum += arr[i];
            }

            if (arr[i] == 20) isBetween = true;
        }

        Console.WriteLine("The sum of numbers between 20 and 40 is" + sum);

        return 0;
    }
}