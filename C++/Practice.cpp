#include <iostream>
#include <cmath>

using namespace std;

#define FOR(i, N) for(int i=0 ; i<N ; ++i)
#define INF 50000

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    int answer[N][N];
    FOR(y, N) FOR(x, N)
    {
        cin >> answer[y][x];
        if(answer[y][x] == 0) answer[y][x] = INF;
    }
    FOR(i, N) FOR(f, N) FOR(t, N)
    {
        answer[f][t] = min(answer[f][t], answer[f][i] + answer[i][t]);
    }
    FOR(y, N)
    {
        FOR(x, N)
        {
            if(answer[y][x] == INF) cout << 0 << ' ';
            else cout << 1 << ' ';
        }
        cout << "\n";
    }

    return 0;
}