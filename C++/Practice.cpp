#include <iostream>
#include <map>

using namespace std;

int X, Y;
bool lettuces[51][51];
bool visited[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void Initialize()
{
    for (int y = 0; y < 51; ++y)
    {
        for (int x = 0; x < 51; ++x)
        {
            lettuces[y][x] = 0;
            visited[y][x] = 0;
        }
    }
}

void Visit(int x, int y)
{
    if(visited[y][x] == true)
    {
        return;
    }
    visited[y][x] = true;

    int nextX, nextY;
    
    for(int i=0 ; i<4 ; ++i)
    {
        nextX = x + dx[i];
        nextY = y + dy[i];

        if(nextX < 0 || nextX >= X || nextY < 0 || nextY >= Y)
        {
            continue;
        }

        if(lettuces[nextY][nextX] == true)
        {
            Visit(nextX, nextY);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int i=0 ; i<T ; ++i)
    {
        Initialize();

        int K;
        cin >> X >> Y >> K;
    
        for(int i=0 ; i<K ; ++i)
        {
            int x, y;
            cin >> x >> y;

            lettuces[y][x] = true;
        }

        int cnt = 0;
        for(int i=0 ; i<Y ; ++i)
        {
            for(int j=0 ; j<X ; ++j)
            {
                if(lettuces[i][j] == true && visited[i][j] == false)
                {
                    cnt++;
                    Visit(j, i);
                }
            }
        }
        cout << cnt << "\n";
    }

    return 0;

}