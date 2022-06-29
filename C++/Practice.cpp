#include <iostream>
#define FOR(i,s,e) for(int i=s;i<e;++i)
#define ll long long int
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, main, sub, cnt = 0;
    cin >> N;

    ll testers[N];

    FOR(i, 0, N) cin >> testers[i];

    cin >> main >> sub;

    FOR(i, 0, N)
    {
        testers[i] -= main;
        cnt++;
        if(testers[i] > 0)
        {
            cnt += testers[i] / sub;
            if(testers[i] % sub > 0) cnt++;
        }
    }

    cout << cnt;

    return 0;
}