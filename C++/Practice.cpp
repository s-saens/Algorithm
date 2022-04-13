#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int* dp;
int* numbers;

void Init()
{
    numbers = new int[N];
    dp = new int[N];
    for(int i=0 ; i<N ; ++i)
    {
        dp[i] = -1;
    }
}

int BIS(int index)
{
    if(dp[index] > -1) return dp[index];

    int maximum = numbers[index];
    for(int i=index+1 ; i<N ; ++i)
    {
        if(numbers[index] < numbers[i]) maximum = max(maximum, numbers[index] + BIS(i));
    }
    dp[index] = maximum;
    return dp[index];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    Init();

    for(int i=0 ; i<N ; ++i) cin >> numbers[i];

    int maximum = 0;
    for(int i=0 ; i<N ; ++i)
    {
        maximum = max(maximum, BIS(i));
    }

    cout << maximum;

    return 0;
}