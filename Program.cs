using System;
using System.Collections.Generic;

namespace Algorithm
{
    class Program
    {
        static void Main(string[] args)
        {
            Random random = new Random();
            
            int N = Convert.ToInt32(Console.ReadLine());

            List<int> list = new List<int>();
            for(int i=0 ; i<N ; ++i)
            {
                list.Add(i);
            }

            for(int i=0 ; i<N ; ++i)
            {
                int a = random.Next(0, N-i);
                Console.Write($"{list[a]} ");
                list.RemoveAt(a); 
            }
        }
    }
}
