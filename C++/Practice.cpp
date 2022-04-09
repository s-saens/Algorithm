#include <iostream>
#include <queue>

using namespace std;

int dirX[6] = {0, 0, 1, -1, 0, 0};
int dirY[6] = {1, -1, 0, 0, 0, 0};
int dirZ[6] = {0, 0, 0, 0, 1 ,-1};

struct Vector3
{
    int x, y, z;
    int days = 0;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y, Z; cin >> X >> Y >> Z;
    int tomatos[Z][Y][X];
    int total = X * Y * Z;

    queue<Vector3> q;

    for(int z=0 ; z<Z ; ++z)
    {
        for(int y=0 ; y<Y ; ++y)
        {
            for(int x=0 ; x<X ; ++x)
            {
                cin >> tomatos[z][y][x];
                Vector3 v;
                v.x = x;
                v.y = y;
                v.z = z;
                v.days = 0;

                if(tomatos[z][y][x] == 1) q.push(v);
                else if(tomatos[z][y][x] == -1) total--;
            }
        }
    }

    int days = 0;
    int rippedCnt = 0;

    while(!q.empty())
    {
        Vector3 f = q.front();
        q.pop();
        rippedCnt++;
        days = f.days;

        for(int i=0 ; i<6 ; ++i)
        {
            int newIndexX = f.x + dirX[i];
            int newIndexY = f.y + dirY[i];
            int newIndexZ = f.z + dirZ[i];

            if(newIndexX >= X || newIndexX < 0
            || newIndexY >= Y || newIndexY < 0
            || newIndexZ >= Z || newIndexZ < 0)
            {
                continue;
            }


            int *state = &tomatos[newIndexZ][newIndexY][newIndexX];

            if(*state == 0)
            {
                *state = 1;
                Vector3 v;
                v.x = newIndexX;
                v.y = newIndexY;
                v.z = newIndexZ;
                v.days = f.days + 1;
                q.push(v);
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