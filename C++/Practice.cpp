#include <iostream>
using namespace std;

bool** screen;

string QT(int sX, int sY, int len)
{
    int cnt0 = 0;
    int cnt1 = 0;
    int unified = true;

    for(int y=sY ; y<sY+len && unified ; ++y)
    {
        for(int x=sX ; x<sX+len && unified ; ++x)
        {
            if(screen[y][x] == 0) cnt0++;
            else if(screen[y][x] == 1) cnt1++;
            if(cnt0 > 0 && cnt1 > 0) unified = false;
        }
    }

    int h = len / 2;
    string ret = "";

    if(unified) return (cnt0 > 0) ? "0" : "1";
    else ret += "(" + QT(sX, sY, h) + QT(sX+h, sY, h) + QT(sX, sY+h, h) + QT(sX+h, sY+h, h) + ")";

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    screen = new bool*[N];
    for(int i=0 ; i<N ; ++i)
    {
        screen[i] = new bool[N];
    }

    for(int y=0 ; y<N ; ++y)
    {
        string s; cin >> s;
        for(int x=0 ; x<N ; ++x)
            screen[y][x] = s[x]-'0';
    }

    cout << QT(0, 0, N);

    return 0;
}