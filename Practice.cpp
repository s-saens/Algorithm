#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Vector2
{
    public:
    int x=0;
    int y=0;

    Vector2 (int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};

bool compare(Vector2& v1, Vector2& v2)
{
    if((v1).y > (v2).y)
    {
        return false;
    }
    else if((v1).y < (v2).y)
    {
        return true;
    }
    // x가 같을 때
    else if((v1).x > (v2).x)
    {
        return false;
    }
    else
    {
        return true;
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // N:세로, M:가로

    cin >> N;

    vector<Vector2> pos;

    for (int i = 0; i < N; ++i)
    {
        int x, y;
        cin >> x >> y;
        Vector2 v = Vector2(x, y);
        pos.push_back(v);
    }

    sort(pos.begin(), pos.end(), compare);

    cout << "\n";
    for (int i = 0; i < N; ++i)
    {
        cout << pos[i].x << " " << pos[i].y << "\n";
    }
}