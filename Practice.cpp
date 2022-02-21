#include <iostream>
#include <string>

using namespace std;

int MIN(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

struct Vector2
{
    int x;
    int y;
};

Vector2* bigger(Vector2* v1, Vector2* v2)
{
    if((*v1).x > (*v2).x)
    {
        return v1;
    }
    else if((*v1).x < (*v2).x)
    {
        return v2;
    }
    else
    {
        if((*v1).y > (*v2).y)
        {
            return v1;
        }
        else
        {
            return v2;
        }
    }

}

void swapVector2(Vector2* arr, int i1, int i2)
{
    Vector2 temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // N:세로, M:가로

    cin >> N;

    Vector2 pos[N];

    for(int i=0 ; i<N ; ++i)
    {
        int x, y;
        cin >> x >> y;
        pos[i].x = x;
        pos[i].y = y;
    }
    
    for(int i=0 ; i<N-1 ; ++i)
    {
        for(int j=i ; j<N-1 ; ++j)
        {
            if(bigger(&pos[j], &pos[j+1]) == &pos[j])
            {
                swapVector2(pos, j, j+1);
            }
        }
    }

    cout << "\n";
    for(int i=0 ; i<N ; ++i)
    {
        cout << pos[i].x << " " << pos[i].y << "\n";
    }
}