#include <iostream>
#include <cmath>
#include <algorithm>
#define ll long long int

using namespace std;

struct V2
{
    ll x, y;
    double size;
    double theta;

    V2()
    {
        x = 0;
        y = 0;
    }
    V2(int _x, int _y)
    {
        x = _x;
        y = _y;
        size = sqrt(x * x + y * y);
        theta = x == 0 && y == 0 ? -1 : acos((double)x / sqrt((double)size));
    }

    V2 operator-(V2 v)
    {
        return V2(x - v.x, y - v.y);
    }

    ll operator*(V2 v) // 내적
    {
        return x * v.x + y * v.y;
    }

    short operator >> (V2 v) // 외적
    {
        ll c = (x * v.y) - (y * v.x);
        if(c < 0) return -1;
        if(c > 0) return 1;
        else return 0;
    }
};

bool CompareTheta(V2 &v1, V2 &v2)
{
    return v1.theta < v2.theta;
}

double S(V2 v1, V2 v2, V2 v3)
{
    double a = (v2-v1).size;
    double b = (v3-v2).size;
    double c = (v1-v3).size;
    double s = (a + b + c) * 0.5;
    return sqrt(s * (s-a) * (s-b) * (s-c));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    V2 p[N];
    for(int i=0 ; i<N ; ++i)
    {
        int x, y;
        cin >> x >> y;
        p[i] = V2(x, y);
    }

    double sum = 0;
    for(int i=2 ; i<N ; ++i)
    {
        V2 O = p[0];
        V2 A1 = p[i-2];
        V2 A = p[i-1];
        V2 B = p[i];
        V2 C = p[(i+1)%N];

        if((B-A) >> (C-B) < 0) // B가 오목한 경우
        {
            sum -= S(O, A1, A);
            sum += S(A, B, A1);
            sum += S(A1, B, O);
        }
        else
        {
            sum += S(O, A, B);
        }
    }

    printf("%.1f", sum);

    return 0;
}