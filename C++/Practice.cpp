#include <iostream>
#include <vector>
#include <cmath>
#define FOR(i,e)for(int i=0;i<e;++i)
#define MAX 1000000
using namespace std;

// dp[x][1] = x가 일반인이면? 모든 친구들이 EA여야 함. = dp[친구][0] 들의 합
// dp[x][0] = x가 EA면? = (dp[연결][0], dp[친구][1]) 중 작은거 들의 합

struct Node
{
    bool v = 0;
    vector<int> links;
};

int dp[MAX][2], N, u, v;
Node tree[MAX];

void Input()
{
    cin >> N;
    FOR(i,N-1)
    {
        cin >> u >> v; u--; v--;
        tree[u].links.push_back(v);
        tree[v].links.push_back(u);
    }
}

void Find(int x)
{
    tree[x].v = true;
    dp[x][0] = 1;
    FOR(i, tree[x].links.size())
    {
        int c = tree[x].links[i];
        if(tree[c].v) continue;
        Find(c);
        dp[x][1] += dp[c][0];
        dp[x][0] += min(dp[c][0], dp[c][1]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Input();
    Find(1);

    cout << min(dp[1][0], dp[1][1]);

    return 0;
}