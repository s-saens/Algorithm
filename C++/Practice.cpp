#include <iostream>

using namespace std;

#define FOR(i, N) for(int i=0 ; i<N ; ++i)

void Swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int GCD(int a, int b)
{
    int r = a % b;
    if(r == 0) return b;
    else return GCD(b, r);
}

int LCM(int a, int b)
{
    if (a < b) Swap(a, b);
    return a * b / GCD(a,b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    FOR(t, T)
    {
        int X, Y, x, y;
        cin >> X >> Y >> x >> y;

        int lcm = LCM(X, Y);

        int cnt = x;
        while(cnt <= lcm)
        {
            int k = cnt % Y;
            if(cnt % Y == 0) k = Y;

            if(k == y) break;

            cnt += X;
        }

        if (cnt > lcm) cout << -1 << "\n";
        else cout << cnt << "\n";
    }

    return 0;
}