#include <iostream>
#include <cmath>
#define FOR(i, s, e) for(int i=s ; i<e ; ++i)
using namespace std;

int cnt = 0, N, *xOnY;

bool isValid(int y)
{
    FOR(i, 0, y) if(xOnY[y] == xOnY[i] || y - i == abs(xOnY[y] - xOnY[i])) return false;
    return true;
}

void find(int y)
{
    if(y == N) { cnt++; return; }
    FOR(i, 0, N) { xOnY[y] = i; if(isValid(y)) find(y+1); }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    xOnY = new int[N];

    find(0);

    cout << cnt;

    return 0;
}