#include <iostream>
#define FOR(i, N) for(int i=0 ; i<N ; ++i)

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    int answer[T];

    FOR(t, T)
    {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int dx = x2-x1;
        int dy = y2-y1;

        if(x1 == x2 && y1 == y2 && r1 == r2) { answer[t] = -1; continue; }

        int d2 = dx * dx + dy * dy;

        int rm = r1 > r2 ? r1 - r2 : r2 - r1; rm *= rm;
        int rp = r1 + r2; rp *= rp;

        if(rm > d2 || rp < d2) { answer[t] = 0; continue; }
        if(rm == d2 || rp == d2) { answer[t] = 1; continue; }
        answer[t] = 2;
    }

    FOR(t, T) cout << answer[t] << "\n";

    return 0;
}