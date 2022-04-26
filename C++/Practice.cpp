#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
#define ll long long
#define FOR(i, s, e) for(int i=s ; i<e ; ++i)

using namespace std;

struct Vector2
{
    ll x, y;
    double size;
    double theta;

    Vector2()
    {
        x = 500000;
        y = 500000;
    }

    Vector2(int _x, int _y)
    {
        x = _x;
        y = _y;
        size = (x * x) + (y * y);
        theta = x == 0 && y == 0 ? -1 : acos( (double)x / sqrt((double)size) );
    }

    Vector2 operator - (Vector2 v)
    {
        return Vector2(x - v.x, y - v.y);
    }

    ll operator * (Vector2 v)
    {
        return (x * v.x) + (y * v.y);
    }

    short operator >> (Vector2 v)  // 외적 z값의 sign 반환. 양수이면 왼쪽 벡터에 대해 오른쪽 벡터는 CCW (왼쪽)
    {
        ll c = (x * v.y) - (y * v.x);
        if(c < 0) return -1;
        if(c > 0) return 1;
        return 0;
    }
};

bool CompareTheta(Vector2& v1, Vector2& v2)
{
    ll dot = v1 * v2;
    if(dot * dot == v1.size * v2.size) return v1.size < v2.size;
    return v1.theta < v2.theta;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int pointCnt; cin >> pointCnt;

    Vector2 p[pointCnt];
    Vector2 b = p[0];

    FOR(i, 0, pointCnt)
    {
        int x, y;
        cin >> x >> y;
        p[i] = Vector2(x, y);
        if(b.y > y) b = p[i];
        else if(b.y == y && b.x < x) b = p[i];
    }

    FOR(i, 0, pointCnt) p[i] = p[i] - b;

    sort(p, p+pointCnt, CompareTheta);

    stack<int> s;
    s.push(0);
    s.push(1);

    FOR(i, 2, pointCnt)
    {
        while(s.size() > 1)
        {
            int second = s.top(); s.pop();
            int first = s.top();

            if((p[second] - p[first]) >> (p[i] - p[first]) > 0) // p[i]가 왼쪽에 있으면 첫번째거 다시 집어넣고 break;
            {
                s.push(second);
                break;
            }
        }
        s.push(i);
    }

    int first = s.top(); s.pop();
    int second = s.top();

    if ((p[second] - p[first]) >> (p[0] - p[first]) != 0)
    {
        s.push(first);
    }

    cout << s.size();

    return 0;
}