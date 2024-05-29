#include <bits/stdc++.h>

int main()
{
   int n, head, i, j, k, seek = 0, max1, diff;
   float avg;

   printf("enter the max range of disk\n");
   scanf("%d", &max1);

   printf("enter the size of queue request\n");
   scanf("%d", &n);

   int queue[n + 1];

   printf("enter the queue\n");
   for (i = 1; i <= n; i++)
   {
      scanf("%d", &queue[i]);
   }

   printf("enter the initial head position\n");
   scanf("%d", &head);
   queue[0] = head;

   for (j = 1; j <= n - 1; j++)
   {
      int now = queue[j], next = queue[j+1];
      diff = abs(next - now);
      seek += diff;
      printf("move is from %d to %d with seek %d\n", now, next, diff);
   }

   printf("total seek time is %d\n", seek);
   avg = seek / (float)(n-1);

   printf("avrage seek time is %f\n", avg);

   return 0;
}