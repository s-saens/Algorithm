#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define FOR(i, s, e) for(int i=s ; i<e ; ++i)
#define FOR_R(i, s, e) for(int i=s ; i>=e ; --i) // both inclusive

int N, M;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int memories[N];
    int costs[N];

    int maxCostSum = 0;
    FOR(i, 0, N) cin >> memories[i];
    FOR(i, 0, N)
    {
        cin >> costs[i];
        maxCostSum += costs[i];
    }
    int maxMemories[maxCostSum+1];
    memset(maxMemories, 0, sizeof(maxMemories));

    FOR(i, 0, N) FOR_R(j, maxCostSum, costs[i])
        maxMemories[j] = max(maxMemories[j], maxMemories[j-costs[i]] + memories[i]);

    FOR(i, 0, maxCostSum+1) if(maxMemories[i] >= M)
    {
        cout << i;
        return 0;
    }
}