#include <iostream>
#define FOR(i,s,e)for(int i=s;i<e;++i)
#define MAX 1001
using namespace std;

long long dp[MAX];

void Init()
{
    dp[0] = 0, dp[1] = 1, dp[2] = 4;
    FOR(i, 3, MAX) dp[i] = dp[i-1] + (i*(i+1)/2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    Init();

    int T; cin >> T;
    FOR(t, 0, T)
    {
        int n; cin >> n;
        printf("%d: %d %lld\n", t+1, n, dp[n]);
    }

    return 0;
}