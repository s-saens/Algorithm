#include <iostream>
#include <algorithm>
using namespace std;

struct Conference
{
    int start = 0;
    int end = 0;
};
bool cmp(Conference& c1, Conference& c2)
{
    if(c1.end < c2.end)
    {
        return true;
    }
    else if(c1.end == c2.end)
    {
        return c1.start < c2.start;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >>N;
    Conference conferences[N];

    for(int i=0 ; i<N ; ++i)
    {
        cin >> conferences[i].start >> conferences[i].end;
    }

    sort(conferences, conferences + N, cmp);

    int cnt = 1;
    Conference lastC = conferences[0];
    for(int i=1 ; i<N ; ++i)
    {
        Conference c = conferences[i];

        if(c.start >= lastC.end)
        {
            cnt++;
            lastC = c;
        }
    }

    cout << cnt;

    return 0;
}