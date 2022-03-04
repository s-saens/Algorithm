#include <iostream>
#include <algorithm>
#include <climits>

#define ull unsigned long long int

using namespace std;

ull DP[1000001];

ull GetMinCnt(int x)
{
    if(DP[x] != -1)
    {
        return DP[x];
    }

    ull minCnt = INT_MAX;

    minCnt = min(minCnt, 1 + GetMinCnt(x - 1));
    if(x%3 == 0) minCnt = min(minCnt, 1 + GetMinCnt(x/3));
    if(x%2 == 0) minCnt = min(minCnt, 1 + GetMinCnt(x/2));

    DP[x] = minCnt;
    return minCnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=1 ; i<1000001 ; ++i)
    {
        DP[i] = -1;
    }
    DP[1] = 0;

    int N;
    cin >> N;

    cout << GetMinCnt(N);

    return 0;
}