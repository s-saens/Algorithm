#include <iostream>
#include <algorithm>
#define FOR(i, s, e) for (int i = s; i < e; ++i)
using namespace std;

int dist(string a, string b)
{
    int cnt = 0;
    FOR(i, 0, 4)
    {
        if (a[i] != b[i])
            cnt++;
    }
    return cnt;
}

int calc(string a, string b, string c)
{
    int sum = 0;
    sum += dist(a, b);
    sum += dist(a, c);
    sum += dist(c, b);
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        string mbtis[N];

        FOR(i, 0, N)
        {
            cin >> mbtis[i];
        }

        int answer = 999999;

        if (N > 32)
        {
            answer = 0;
        }
        else
        {
            FOR(i, 0, N - 2)
            FOR(j, i + 1, N - 1)
            FOR(k, j + 1, N)
            {
                answer = min(answer, calc(mbtis[i], mbtis[j], mbtis[k]));
            }
        }

        cout << answer << '\n';
    }

    return 0;
}