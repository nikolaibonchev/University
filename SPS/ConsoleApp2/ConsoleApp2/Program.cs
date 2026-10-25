using System;
using System.Collections.Generic;

class Program
{
    static void displayPlaneMap(Dictionary<int, Dictionary<char, char>> arr) { 
        for(int i = 1; i <= arr.Count; i++)
        {
            for (char c = 'A'; c <= 'F'; c++)
            {
                Console.WriteLine(arr[i][c]);
            }
        }
    }
    static void Reservtion() { }
    static int Main()
    {
        var arr = new Dictionary<int, Dictionary<char, char>>();

        for (int r = 1; r <= 4; r++)
        {
            arr[r] = new Dictionary<char, char>();
            for (char c = 'A'; c <= 'F'; c++)
            {
                arr[r][c] = '*';
            }
        }

        displayPlaneMap(arr);

        Console.WriteLine(arr[1]['A']);
        return 0;
    }
}