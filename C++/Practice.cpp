#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int dirX[4] = {0, 0, 1, -1};
int dirY[4] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y; cin >> X >> Y;
    int tomatos[Y][X];
    int total = X * Y;

    queue<pair<pair<int, int>, int> > q;

    for(int y=0 ; y<Y ; ++y)
    {
        for(int x=0 ; x<X ; ++x)
        {
            cin >> tomatos[y][x];
            if(tomatos[y][x] == 1) q.push(make_pair(make_pair(x, y), 0));
            else if(tomatos[y][x] == -1) total--;
        }
    }

    int days = 0;
    int rippedCnt = 0;
    while(!q.empty())
    {
        pair<pair<int, int>, int> f = q.front();
        q.pop();
        rippedCnt++;
        days = f.second;

        for(int i=0 ; i<4 ; ++i)
        {
            int newIndexY = f.first.second + dirY[i];
            int newIndexX = f.first.first + dirX[i];
            if(newIndexY >= Y || newIndexY < 0 || newIndexX >= X || newIndexX < 0)
            {
                continue;
            }

            int *state = &tomatos[newIndexY][newIndexX];

            if(*state == 0)
            {
                *state = 1;
                q.push(make_pair(make_pair(newIndexX, newIndexY), f.second + 1));
            }
        }
    }
    if(rippedCnt == total)
    {
        cout << days;
    }
    else
    {
        cout << -1;
    }

    return 0;
}