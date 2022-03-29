#include <iostream>
#define ll long long int

using namespace std;

int a, b, c;

ll power(ll x, ll y) // x^y
{
    if(y == 0)
    {
        return 1;
    }
    if(y == 1)
    {
        return x;
    }

    if(y%2 == 1)
    {
        return power(x, y-1) * x;
    }
    ll h = power(x, y/2) % c;

    return (h * h) % c;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c;

    cout << power(a, b) % c;

    return 0;
}