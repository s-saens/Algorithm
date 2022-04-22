#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, N) for(int i=0 ; i<N ; ++i)

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int Y, X;

int** numbers;

int GetFuckingMax(int x, int y)
{
    int maxSum = 0;
    FOR(i, 4)
    {
        int sum = numbers[y][x];
        FOR(j, 3)
        {
            int nd = (i+j)%4;
            int nx = x + dx[nd];
            int ny = y + dy[nd];
            if(nx < 0 || nx >= X || ny < 0 || ny >= Y) continue;
            sum += numbers[ny][nx];
        }
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int GetMax(int x, int y, int cnt, int lastI)
{
    if(cnt == 3) 
    {
        return numbers[y][x];
    }
    int maximum = 0;
    FOR(i, 4)
    {
        if(lastI%2 == 0 && i == lastI + 1) continue;
        if(lastI%2 == 1 && i == lastI - 1) continue;

        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= X || ny < 0 || ny >= Y) continue;
        maximum = max(maximum, numbers[y][x] + GetMax(nx, ny, cnt+1, i));
    }
    return maximum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> Y >> X;

    numbers = new int*[Y];
    FOR(y, Y) FOR(x, X) numbers[y] = new int[X];

    FOR(y, Y) FOR(x, X)
    {
        cin >> numbers[y][x];
    }

    int sum = 0;
    FOR(y, Y) FOR(x, X)
    {
        sum = max(sum, GetMax(x, y, 0, -1));
        sum = max(sum, GetFuckingMax(x, y));
    }

    cout << sum;

    return 0;
}