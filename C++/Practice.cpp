#include <iostream>
#include <cmath>
#define FOR(i,e)for(int i=0;i<e;++i)
#define MAX 1001
using namespace std;

struct V2
{
    int x, y;

    V2 operator-(V2 v)
    {
        V2 newV;
        newV.x = x - v.x;
        newV.y = y - v.y;
        return newV;
    }

    short operator>>(V2 v) // 외적. +시계 -반시계
    {
        int c = (x * v.y) - (y * v.x);
        if (c < 0) return -1;
        if (c > 0) return 1;
        else return 0;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    V2 p[3];
    FOR(i,3) cin >> p[i].x >> p[i].y;

    short ccw = (p[1]-p[0]) >> (p[2]-p[0]);

    double area = 0;
    FOR(i, 3) area += p[i].x * (p[(i+1)%3].y - p[(i+2)%3].y);
    area /= 2;

    int N, cnt=0; cin >> N;
    
    FOR(i, N)
    {
        V2 t;
        cin >> t.x >> t.y;

        bool yes = 1;

        FOR(j, 3)
        {
            V2 a=p[j], b=p[(j+1)%3];
            V2 ab = b-a;
            V2 at = t-a;

            short c = ab >> at;

            if (c != ccw && c != 0) yes = 0;
        }

        if(yes) cnt++;
    }

    printf("%.1f\n%d", abs(area), cnt);


    return 0;
}