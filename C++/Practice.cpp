#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

#define FOR(i,s,e) for(int i=s; i<e; ++i)
#define FOR_R(i,s,e) for(int i=s; i>=e; --i) // both inclusive

struct Point
{
    int x, y, w;
    char c;
    Point(int _x, int _y, int _w, char _c)
    {
        x = _x;
        y = _y;
        w = _w;
        c = _c;
    }
};

bool cmp(Point& p1, Point& p2)
{
    return p1.w > p2.w;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2; cin >> s1 >> s2;
    int len1 = s1.length()+1, len2 = s2.length()+1;

    int weight[len2][len1];
    FOR(y, 0, len2) weight[y][0] = 0;
    FOR(x, 1, len1) weight[0][x] = 0;

    int maximum = 0;

    vector<Point> s;
    stack<char> answer;

    FOR(y, 1, len2) FOR(x, 1, len1)
    {
        weight[y][x] = max(weight[y-1][x], weight[y][x-1]);
        if(s1[x-1] == s2[y-1])
        {
            weight[y][x] = weight[y-1][x-1] + 1;
            maximum = max(maximum, weight[y][x]);
        }

        if (weight[y][x] > weight[y - 1][x] && weight[y][x] > weight[y][x - 1])
            s.push_back(Point(x, y, weight[y][x], s1[x - 1]));
    }
    cout << maximum << "\n";

    if(s.size() == 0) return 0;

    sort(s.begin(), s.end(), cmp);

    int lx = s[0].x + 1, ly = s[0].y + 1;
    FOR(i, 0, s.size())
    {
        Point p = s[i];
        // cout << p.x << ',' << p.y << "\n";
        if(p.y >= ly || p.x >= lx) continue;
        lx = p.x; ly = p.y;
        answer.push(p.c);
    }

    while(!answer.empty())
    {
        cout << answer.top(); answer.pop();
    }

    return 0;
}