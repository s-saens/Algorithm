#include <iostream>
#include <algorithm>
#define FOR(i,e)for(int i=0;i<e;++i)
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K; cin >> N >> K;
    int h[N], d[N-1];

    int totalCost = 0;

    FOR(i, N) cin >> h[i];
    FOR(i, N-1)
    {
        d[i] = h[i+1] - h[i];
        totalCost += d[i];
    }

    sort(d, d+N-1);

    FOR(i, K-1) totalCost -= d[N-2-i];

    cout << totalCost;

    return 0;
}