#include <iostream>
#include <algorithm>

using namespace std;

struct Point
{
    bool horizontal = false;
    bool vertical = false;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    cin >> N;

    string operation;
    cin >> operation;
    int len = operation.length();

    Point points[N][N];

    int nowX = 0, nowY = 0;

    for (int i = 0; i < len ; ++i)
    {
        switch (operation[i])
        {
            case 'U': // UP
                if (nowY > 0)
                {
                    points[nowY][nowX].vertical = true;
                    nowY--;
                    points[nowY][nowX].vertical = true;
                }
                break;
            case 'D': // DOWN
                if (nowY < N-1)
                {
                    points[nowY][nowX].vertical = true;
                    nowY++;
                    points[nowY][nowX].vertical = true;
                }
                break;
            case 'L': // LEFT
                if (nowX > 0)
                {
                    points[nowY][nowX].horizontal = true;
                    nowX--;
                    points[nowY][nowX].horizontal = true;
                }
                break;
            case 'R': // RIGHT
                if (nowX < N-1)
                {
                    points[nowY][nowX].horizontal = true;
                    nowX++;
                    points[nowY][nowX].horizontal = true;
                }
                break;

            default:
                break;
        }
    }

    for(int i=0 ; i<N ; ++i)
    {
        for(int j=0 ; j<N ; ++j)
        {
            char c;
            Point& p = points[i][j];
            if(p.horizontal && p.vertical) // +
            {
                c = '+';
            }
            else if(p.horizontal) // |
            {
                c = '-';
            }
            else if(p.vertical) // -
            {
                c = '|';
            }
            else // .
            {
                c = '.';
            }
            cout << c;
        }
        cout << "\n";
    }

    return 0;
}