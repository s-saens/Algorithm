#include <iostream>

using namespace std;

struct Vector2
{
    int x;
    int y;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Vector2 points[3];

    for(int i=0 ; i<3 ; ++i)
    {
        cin >> points[i].x >> points[i].y;
    }

    // 유일 x, y의 index 찾기
    int xIndex = -1;
    int yIndex = -1;

    for(int i=0 ; i<3 ; ++i)
    {
        if(points[i].x != points[(i+1)%3].x  &&  points[i].x != points[(i+2)%3].x)
        {
            xIndex = i;
        }
        if(points[i].y != points[(i+1)%3].y  &&  points[i].y != points[(i+2)%3].y)
        {
            yIndex = i;
        }
    }

    cout << points[xIndex].x << " " << points[yIndex].y;
}