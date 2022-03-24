#include <iostream>
#include <algorithm>

#define ull __uint128_t

using namespace std;

ull comb[101][101];

ull Comb(int n, int r)
{
    if(comb[n][r] > 0)
    {
        return comb[n][r];
    }
    if(r == 1 || r == n-1)
    {
        return n;
    }
    if(r == 0 || r == n)
    {
        return 1;
    }

    comb[n][r] = Comb(n - 1, r - 1) + Comb(n - 1, r);
    return comb[n][r];
}

string Uint128ToString(ull a)
{
    string ret = "";

    while(a > 0)
    {
        ret += to_string((int)(a % 10));
        a /= 10;
    }

    reverse(ret.begin(), ret.end());

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0 ; i<101 ; ++i)
    {
        for(int j=0 ; j<101 ; ++j)
        {
            comb[i][j] = 0;
        }
    }

    int n, r;
    cin >> n >> r;

    cout << Uint128ToString(Comb(n, r));

    return 0;
}