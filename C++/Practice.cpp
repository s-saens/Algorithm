#include <iostream>
#include <algorithm>
#define FOR(i, s, e) for(int i=s ; i<e ; ++i)
#define INF 20000000000
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    ll weights[N][N];
    FOR(i, 0, N) FOR(j, 0, N)
    {
        weights[i][j] = i == j ? 0 : INF;
    }

    FOR(i, 0, M)
    {
        int f, t; ll w;
        cin >> f >> t >> w;
        f--; t--;

        weights[f][t] = min(weights[f][t], w);
    }

    FOR(k, 0, N) FOR(i, 0, N) FOR(j, 0, N) weights[i][j] = min(weights[i][j], weights[i][k] + weights[k][j]);


    FOR(i, 0, N)
    {
        FOR(j, 0, N)
        {
            if(weights[i][j] == INF) weights[i][j] = 0;
            cout << weights[i][j] << ' ';
        }
        cout << '\n';
    }


    return 0;
}