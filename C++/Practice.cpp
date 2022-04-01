#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int m[N][N];

    for(int x=0 ; x<N ; ++x)
    {
        for(int y=0 ; y<N ; ++y)
        {
            cin >> m[x][y];
            if(y > 0)
            {
                m[x][y] += m[x][y-1];
            }
            if(x > 0)
            {
                m[x][y] += m[x-1][y];
            }
            if(y>0 && x>0)
            {
                m[x][y] -= m[x-1][y-1];
            }
        }
    }

    for(int i=0 ; i<M ; ++i)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;

        int answer = m[x2][y2];
        if(y1 > 0)
        {
            answer -= m[x2][y1-1];
        }
        if(x1 > 0)
        {
            answer -= m[x1-1][y2];
        }
        if(y1>0 && x1>0)
        {
            answer += m[x1-1][y1-1];
        }
        cout << answer << "\n";
    }


    return 0;
}