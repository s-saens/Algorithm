#include <iostream>
#define FOR(i,N) for(int i=0 ; i<N ; ++i)


using namespace std;


short dx[4] = {0, 0, -1, 1};
short dy[4] = {-1, 1, 0, 0};

int N;
char **nodes;
bool **visited1;
bool **visited2;

void Find1(int x, int y, char last)
{
    if(x<0 || x>=N || y<0 || y>=N || visited1[y][x] || last != nodes[y][x]) return;

    visited1[y][x] = true;

    FOR(i, 4)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        Find1(nx, ny, nodes[y][x]);
    }
}

void Find2(int x, int y, char last)
{
    if (x < 0 || x >= N || y < 0 || y >= N || visited2[y][x]) return;
    if(last == 'B' && nodes[y][x] != 'B') return;
    if(last != 'B' && nodes[y][x] == 'B') return;

    visited2[y][x] = true;

    FOR(i, 4)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        Find2(nx, ny, nodes[y][x]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    nodes = new char*[N];
    visited1 = new bool *[N];
    visited2 = new bool *[N];
    FOR(i, N)
    {
        nodes[i] = new char[N];
        visited1[i] = new bool[N];
        visited2[i] = new bool[N];
    }


    FOR(y, N) FOR(x, N) cin >> nodes[y][x];

    int cnt1 = 0;
    int cnt2 = 0;

    FOR(y, N) FOR(x, N) if(!visited1[y][x])
    {
        cnt1++;
        Find1(x, y, nodes[y][x]);
    }
    FOR(y, N) FOR(x, N) if(!visited2[y][x])
    {
        cnt2++;
        Find2(x, y, nodes[y][x]);
    }

    cout << cnt1 << "\n" << cnt2;

    return 0;
}