#include <iostream>
#include <algorithm>
#define FOR(i, s, e) for(int i=s ; i<e ; ++i)

using namespace std;

int X, Y;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

string* alphabets;

int DFS(int x, int y, unsigned int flagBits)
{
    if (x < 0 || x >= X || y < 0 || y >= Y) return 0;


    char c = alphabets[y][x];
    int index = c - 'A';

    if(index < 0)
    {
        cout << x << ',' << y << "\n";
    }

    if (flagBits & (1 << index)) return 0;

    int maximum = 0;

    flagBits |= (1 << index);
    FOR(d, 0, 4)
    {
        int nx = x + dx[d];
        int ny = y + dy[d];
        maximum = max(maximum, 1 + DFS(nx, ny, flagBits));
    }
    return maximum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> Y >> X;

    alphabets = new string[Y];

    FOR(y, 0, Y) cin >> alphabets[y];

    int d = DFS(0, 0, 0);

    cout << d;

    return 0;
}