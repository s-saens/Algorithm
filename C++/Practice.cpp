#include <iostream>
#include <algorithm>
#define ll long long
#define FOR(i,s,e) for(int i=s ; i<e; ++i)
using namespace std;

char sign(ll a)
{
    return a == 0 ? '0' : a < 0 ? '-' : '+';
}

bool sameSign(ll a, ll b)
{
    return sign(a) == sign(b);
}

int main()
{
    int T = 3;
    while(T--)
    {
        int N; cin >> N;
        ll num[N];
        FOR(i, 0, N) cin >> num[i];

        sort(num, num+N);

        int l=0, r=N-1;

        char lastSign = sign(num[l]);
        bool broken = false;

        while (l < r && !sameSign(num[l], num[r]))
        {
            ll sum = num[l] + num[r];
            if(sum < 0)
            {
                num[l] = sum;
                r--;
            }
            else if (sum > 0)
            {
                num[r] = sum;
                l++;
            }
            else
            {
                r--; l++;
            }

            lastSign = sign(sum);
        }

        if(l == r) lastSign = sign(num[l]);

        cout << lastSign << '\n';
    }
    return 0;
}