#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int dp[1000001];
int answer[1000001];

void Init()
{
    for(int i=0 ; i<1000001 ; ++i) dp[i] = -1;
    dp[1] = 0;
}

int F(int x)
{
    if(dp[x] > -1)
    {
        return dp[x];
    }

    int minimum = 1 + F(x-1);
    answer[x] = x-1;
    if(x%2 == 0)
    {
        int a = 1 + F(x/2);
        if (a < minimum)
        {
            minimum = a;
            answer[x] = x/2;
        }
    }
    if(x%3 == 0)
    {
        int a = 1 + F(x/3);
        if (a < minimum)
        {
            minimum = a;
            answer[x] = x/3;
        }
    }

    dp[x] = minimum;
    return minimum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Init();

    int X; cin >> X;

    int m = F(X);
    cout << m << "\n";

    int k = X;
    for(int i=0 ; i<m ; ++i)
    {
        cout << k << ' ';
        k = answer[k];
    }
    cout << 1;

    return 0;
}