#include <iostream>
#include <cmath>
using namespace std;

int f[15];

int factorial(int n)
{
    if(f[n] != -1)
    {
        return f[n];
    }
    if(n == 0)
    {
        return 1;
    }
    if(n == 1)
    {
        return 1;
    }

    f[n] = n * factorial(n-1);
    return f[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0 ; i<15 ; ++i)
    {
        f[i] = -1;
    }

    int n, r;

    cin >> n >> r;

    int answer = factorial(n) / factorial(n-r) / factorial(r);

    cout << answer;

    return 0;
}