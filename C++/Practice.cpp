#include <iostream>
#include <algorithm>
#define FOR(i,e) for(int i=0 ; i<e; ++i)

using namespace std;

int Y, X, cnt;
char arr[51][51];

int main()
{
    cin >> Y >> X;
    cnt = Y * X;

    bool vY[Y], vX[X];
    FOR(y, Y) vY[y] = false;
    FOR(x, X) vX[x] = false;

    int cY = Y, cX = X;

    FOR(y, Y) FOR(x, X)
    {
        cin >> arr[y][x];
        if(arr[y][x] == 'X')
        {
            if(!vY[y])
            {
                vY[y] = true;
                cY--;
            }
            if(!vX[x])
            {
                vX[x] = true;
                cX--;
            }
        }
    }

    cout << max(cY, cX);

    return 0;
}