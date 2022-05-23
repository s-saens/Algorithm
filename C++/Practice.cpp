#include <iostream>
#include <cstring>
#define FOR(i, s, e) for(int i=s ; i<e ; ++i)

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;

    int answers[T];

    FOR(t, 0, T)
    {
        int N; cin >> N;
        int next[N];
        bool isTeam[N];
        answers[t] = 0;

        FOR(i, 0 , N) { cin >> next[i]; next[i]--; isTeam[i] = false; }

        FOR(i, 0, N) // cur가 어딘가로 돌아왔을 때(v[cur] == 1), cur를 다시 돌려주면서 isTeam을 체크해주기.
        {
            int cur = i;
            if(isTeam[cur]) continue;

            bool v[N]; // 이 사이클에서 이미 방문되었는지 여부
            memset(v, 0, sizeof(v));

            while(!v[cur])
            {
                v[cur] = true;

                cur = next[cur];
            }

            int lastCur = cur;
            isTeam[cur] = true;
            cur = next[cur];
            while(cur != lastCur)
            {
                isTeam[cur] = true;

                cur = next[cur];
            }
        }

        FOR(i, 0, N) if(!isTeam[i]) answers[t]++;
    }

    FOR(t, 0, T) cout << answers[t] << "\n";

    return 0;
}