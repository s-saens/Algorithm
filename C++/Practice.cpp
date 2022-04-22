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

        int cnt;
        for (cnt = x; cnt <= lcm; cnt += X)
        {
            int temp = (cnt % Y == 0) ? Y : cnt % Y;
            if (temp == y)
            {
                cout << cnt << "\n";
                break;
            }
        }
        if (cnt > lcm) cout << -1 << "\n";
    }

    return 0;
}