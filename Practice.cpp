#include <iostream>
#include <string>

using namespace std;


int DP[1001];


int MAX(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int lis(int startIndex, int N, int* arr)
{
    if(DP[startIndex] != -1)
    {
        return DP[startIndex];
    }

    int last_lis = 1;
    for(int i=startIndex+1; i<N ; ++i)
    {
        if(arr[startIndex] < arr[i])
        {
            int now_lis = 1 + lis(i, N, arr);
            last_lis = MAX(last_lis, now_lis);
        }
    }
    DP[startIndex] = last_lis;
    return last_lis;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0 ; i<1001 ; ++i)
    {
        DP[i] = -1;
    }
    
    int N;

    cin >> N;

    int arr[N];

    for(int i=0 ; i<N ; ++i)
    {
        cin >> arr[i];
    }

    int longest = 0;

    for(int i=0 ; i<N ; ++i)
    {
        longest = MAX(lis(i, N, arr), longest);
    }

    cout << longest;
    
}