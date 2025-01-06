#include <iostream>
#define FOR(i,s,e) for(int i=s ; i<e; ++i)
#define K 51
using namespace std;

int Y, X, answer = 0;
bool A[K][K], B[K][K];

void flip(int x, int y)
{
    answer++;
    FOR(i, 0, 3) FOR(j, 0, 3)
    {
        A[y + i][x + j] = !A[y + i][x + j];
    }
}

void set(bool a)
{
    FOR(y, 0, Y)
    {
        string k; cin >> k;
        FOR(x, 0, X) if(a) A[y][x] = k[x] - '0'; else B[y][x] = k[x] - '0';
    }
}

int main()
{
    cin >> Y >> X;

    set(true);
    set(false);

    if(Y < 3 || X < 3)
    {
        FOR(y,0,Y) FOR(x,0,X) if(A[y][x]!=B[y][x]) answer = -1;
        cout << answer;
        return 0;
    }

    FOR(y, 0, Y) FOR(x, 0, X)
    {
        if(A[y][x] != B[y][x]) 
        {
            if (x < X-2 && y < Y-2) flip(x,y);
            else
            {
                cout << -1;
                return 0;
            }
        }
    }

    cout << answer;
    return 0;
}