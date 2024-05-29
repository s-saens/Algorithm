#include <bits/stdc++.h>
using namespace std;

int find(int d[], int n, int disk)
{
  for (int i = 0; i < n - 1; i++)
  {
    if (d[i] > disk)
    {
      return i;
      break;
    }
  }
}

int main()
{
  int i, j, n;
  int disk; // location of head
  int temp, max;
  int no_t;

  printf("enter total number of tracks\n");
  scanf("%d", &no_t);

  printf("enter number of location\n");
  scanf("%d", &n);
  int d[n + 1]; // disk queue

  printf("enter position of head\n");
  scanf("%d", &disk);

  printf("enter elements of disk queue\n");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &d[i]);
  }

  sort(d, d+n);

  printf("elements after sorting\n");

  for (i = 0; i < n; i++)
  {
    printf("%d ", d[i]);
  }

  int prev_head;
  printf("\nenter previous head position\n");
  scanf("%d", &prev_head);

  int c;
  int sum = 0;

  if (prev_head > disk)
    c = 1;
  else
    c = 2;

  // go towards left
  if (c == 1)
  {
    int previous = find(d, n, disk);
    previous--;

    sum += abs(disk - d[previous]);

    for (i = previous; i >= 0; i--)
    {
      printf("%d->", d[i]);
      if (i != 0)
        sum += abs(d[i] - d[i - 1]);
      else if (i == 0)
        sum += d[i];
    }

    printf("0->%d->", no_t - 1);
    // (왼쪽 끝 -> 오른쪽 끝) + (오른쪽 끝 -> 가장 큰 디스크)
    sum += (no_t - 1) + ((no_t - 1) - d[n - 1]);

    for (i = n - 1; i >= previous + 1; i--)
    {

      if (i != previous + 1)
      {
        printf("%d->", d[i]);
        sum += abs(d[i] - d[i - 1]);
      }
      else printf("%d", d[i]);
    }

    printf("\nmovement of total cylinders %d\n", sum);
  }

  // go towards right
  else if (c == 2)
  {
    int previous = find(d, n, disk);
    previous--;

    sum += abs(d[previous] - disk);

    for (i = previous; i < n; i++)
    {
      printf("%d->", d[i]);
      if (i != n - 1)
        sum += abs(d[i + 1] - d[i]);
      else if (i == n - 1)
        sum += abs(no_t - 1 - d[i]);
    }

    printf("%d->0->", no_t - 1);

    // (오른쪽 끝 -> 왼쪽 끝) + (왼쪽 끝 -> 가장 작은 디스크)
    sum += (no_t - 1) + (d[0]);

    for (i = 0; i <= previous - 1; i++)
    {
      if (i != previous - 1)
      {
        printf("%d->", d[i]);
        sum += abs(d[i + 1] - d[i]);
      }
      else
      {
        printf("%d", d[i]);
      }
    }

    printf("\nmovement of total cylinders %d\n", sum);
  }

  return 0;
}