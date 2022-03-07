#include <iostream>

using namespace std;

short bitCount(short x)
{
    if(x == 0) return 0;
    return x % 2 + bitCount(x/2);
}

int main()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned int X;
    cin >> X;

    cout << bitCount(X);

    return 0;
}