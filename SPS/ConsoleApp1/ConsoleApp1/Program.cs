class Program
{
    static float avg(float n, float m)
    {
        float avg = (n + m) / 2;
        return avg;
    }
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
        int[] arr = { 1, 2, 3, 0, 0, 6, 7, 8, 9, 10 };
        
        for(int i = 0; i < 10; i++)
        {
            if(arr[i] == 0 && arr[i+1] == 0)
            {
                Console.WriteLine("It has two 0s one after another");
                break;
            }
        }*/

        /* задача 4
        int[] arr = { 1, 2, 3, 20, 1, 1, 1, 1, 1, 40 };
        int sum = 0;
        bool isBetween = false;

        for (int i = 0; i < 10; i++)
        {
            if (arr[i] == 40) isBetween = false;

            if (isBetween)
            {
                sum += arr[i];
            }

            if (arr[i] == 20) isBetween = true;
        }

        Console.WriteLine("The sum of numbers between 20 and 40 is " + sum);*/

        /* задача 5
        int[] arr = { 1, 2, 3, 0, 0, 6, 7, 8, 9, 10 };

        for (int i = 0; i < 10; i++)
        {
            if (arr[i] == 0) arr[i] += 1;
        }

        for (int i = 0; i < 10; i++)
        {
            Console.Write(arr[i] + " ");
        }*/

        /* задача 6
        int[] arr = { 1, 2, 3, 0, 0, 6, 7, 4, 9, 10 };
        int sum = 0;

        for (int i = 0; i < 10; i++)
        {
            if (arr[i] % 10 == 3 || arr[i] % 10 == 4 ) sum += i;
        }

        Console.WriteLine("The sum of indexes is " + sum);*/

        /* задача 7
        int[] arr = { 1, 2, 3, 0, 0, 6, 7, 4, 9, 10 };

        for (int i = 0; i < 10; i+=2)
        {
            Console.Write(avg(arr[i], arr[i + 1]) + " ");
        }*/

        /* задача 8
        int[] arr = { 1, 2, 3, 24, 9, 6, 7, 4, 9, 10 };
        int min = arr[0];
        int max = arr[0];

        for (int i = 0; i < 10; i++)
        {
            if (arr[i] > max) max = arr[i];
            if (arr[i] < min) min = arr[i];
        }

        Console.WriteLine("The difference between max and min is: " + (max - min));*/

        /* задача 9
        int[] arr = { 1, 2, 3, 24, 9, 6, 7, 4, 9, 10 };
        int min = arr[0];
        int max = arr[0];

        int min_i = 0;
        int max_i = 0;

        for (int i = 0; i < 10; i++)
        {
            if (arr[i] > max) 
            {
                max = arr[i];
                max_i = i;
            }

            if (arr[i] < min)
            {
                min = arr[i];
                min_i = i;
            }
        }  
        
        int temp = arr[max_i];
        arr[max_i] = arr[min_i];
        arr[min_i] = temp;

        for (int i = 0; i < 10; i++)
        {
            Console.Write(arr[i] + " ");
        }*/

        /* задача 10
        int[] a = { 1, 2, 3, 24, 9, 6, 6, 4, 9, 10 };
     
        for (int i = 0; i < 10; i++)
        {
            if (a[i] < i) a[i] *= a[i];
            if (a[i] == i) a[i] *= -1;
            if (a[i] > i) a[i] -= 1;
        }

        for (int i = 0; i < 10; i++)
        {
            Console.Write(a[i] + " ");
        }*/

        return 0;
    }
}