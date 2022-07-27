#include <iostream>
#include <cmath>
#define FOR(i, e) for (int i=0; i<e; ++i)
using namespace std;

int _x1, _y1, r1, _x2, _y2, _r2;

int Solve()
{
    if(_x1==_x2 && _y1==_y2 && r1==_r2) return -1;

    int dx=_x2-_x1, dy=_y2-_y1, dd=dx*dx+dy*dy, rp=_r2+r1, rn=_r2-r1;
    rp*=rp; rn*=rn;
    if(rp == dd) return 1; // 외접
    if(rp < dd) return 0; // 원 밖에서 안만남

    double minR=(double)min(r1, _r2), maxR=(double)max(r1, _r2);
    double d = sqrt(dd);
    if(d + minR == maxR) return 1;
    if(d + minR < maxR) return 0;

    return 2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    short answers[T];
    FOR(t, T)
    {
        cin >> _x1 >> _y1 >> r1 >> _x2 >> _y2 >> _r2;
        answers[t] = Solve();
    }

    FOR(t, T) cout << answers[t] << '\n';

    return 0;
}