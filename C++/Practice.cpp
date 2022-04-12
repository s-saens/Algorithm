#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long int

struct Line
{
    ll start = 0;
    ll end = 0;
    Line()
    {
        start = 0; end = 0;
    }
    Line(int s, int e)
    {
        if(s < e) { start = s; end = e; }
        else { start = e; end = s;}
    }
    ll Length()
    {
        return end - start;
    }
};

bool cmp(Line& l1, Line& l2)
{
    return l1.start < l2.start;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    Line lines[N];
    for(int i=0 ; i<N ; ++i)
    {
        int a, b;
        cin >> a >> b;
        lines[i] = Line(a, b);
    }
    sort(lines, lines + N, cmp);

    Line lastLine = lines[0];
    ll sum = 0;
    for(int i=1 ; i<N ; ++i)
    {
        if(lines[i].start <= lastLine.end && lines[i].end >= lastLine.end)
        {
            lastLine = Line(lastLine.start, lines[i].end);
        }
        else if(lines[i].start > lastLine.end)
        {
            sum += lastLine.Length();
            lastLine = lines[i];
        }
    }
    sum += lastLine.Length();

    cout << sum;

    return 0;
}