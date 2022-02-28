#include <iostream>
#include <cmath>
#define ull unsigned long long
using namespace std;

ull M = 1234567891;

ull GetPower31(ull n)
{
    ull ret = 1;
    for(int i=0 ; i<n ; ++i)
    {
        ret %= M;
        ret *= 31;
        ret %= M;
    }
    return ret%M;
}

ull Hashing(string s) // a = 97
{
    ull sum = 0;
    int len = s.length();
    for(int i=0 ; i<len ; ++i)
    {
        sum += ( (s[i]-96) * GetPower31(i) ) % M;
    }
    return sum % M;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int L;
    string s;
    cin >> L >> s;

    cout << Hashing(s);

    return 0;
}