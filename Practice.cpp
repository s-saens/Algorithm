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

int longestBiotic(int startIndex, int last_changeCnt, int last_increment, int N, int* arr)
{
    if(DP[startIndex] != -1)
    {
        return DP[startIndex];
    }

    int last_lis = 1;

    for(int i=startIndex+1; i<N ; ++i)
    {
        // now_ : 현재 i에 대한 값
        // last_ : 현재 함수 전체에 대한 값
        int now_changeCnt = last_changeCnt;
        int now_increment = last_increment;

        // 감소한 경우
        if(arr[startIndex] > arr[i])
        {
            now_increment = -1;
            // 이전에 증가하고 있었던 경우
            if(last_increment > 0)
            {
                now_changeCnt++;
            }
        }
        // 증가한 경우
        else if(arr[startIndex] < arr[i])
        {
            now_increment = 1;
            // 이전에 감소하고 있었던 경우 : ch에 관계 없이 바이오틱 X
            if(last_increment < 0)
            {
                continue;
            }
        }
        // 그대로인 경우 : ch에 관계 없이 바이오틱 X
        else
        {
            continue;
        }

        if(now_changeCnt > 1)
        {
            continue;
        }

        last_lis = MAX(last_lis, 1 + longestBiotic(i, now_changeCnt, now_increment, N, arr));
    }

    DP[startIndex] = MAX(last_lis, startIndex);
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
        longest = MAX(longestBiotic(i, 0, 0, N, arr), longest);
    }

    cout << longest;
    
}