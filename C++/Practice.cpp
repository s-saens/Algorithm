#include <iostream>
#include <vector>
#define FOR(i,e) for(int i=0 ; i<e; ++i)

using namespace std;

vector<int> tree[100001];
int dp[100001];

int dfs(int n)
{
    if(dp[n] > -1) return dp[n];

    dp[n] = 1;

    vector<int> &v = tree[n];

    FOR(i, v.size())
    {
        int l = v[i];
        if(dp[l] == -1) dp[n] += dfs(l);
    }

    return dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, R, Q;
    cin >> N >> R >> Q;

    FOR(i, N-1)
    {
        int u, v; cin >> u >> v;
        tree[u-1].push_back(v-1);
        tree[v-1].push_back(u-1);
    }
    FOR(i, N) dp[i] = -1;

    R--;
    dfs(R);

    FOR(i, Q)
    {
        int q; cin >> q; q--;
        cout << dp[q] << '\n';
    }
}