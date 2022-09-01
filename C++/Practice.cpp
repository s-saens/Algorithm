#include <iostream>
#include <algorithm>
#define FOR(i,e)for(int i=0;i<e;++i)
#define ll long long int
using namespace std;

ll N=1, *heights, *segtree;

int SetSegTree(int ni, int l, int r)
{
    if(l == r)
    {
        segtree[ni] = l;
        return l;
    }

    int m = (l+r)/2;
    int cr = (ni+1)*2;
    int cl = cr - 1;

    int leftShortestIndex = SetSegTree(cr, m+1, r);
    int rightShortestIndex = SetSegTree(cl, l, m);

    int ret;
    if(heights[leftShortestIndex] < heights[rightShortestIndex]) ret = leftShortestIndex;
    else ret = rightShortestIndex;

    segtree[ni] = ret;
    return ret;
}

int FindShortestIndex(int ni, int l, int r, int nl, int nr)
{
    int m = (nl+nr)/2;
    int cr = (ni+1)*2;
    int cl = cr-1;
    if(l > nr || r < nl) return -2;
    if(l <= nl && nr <= r) return segtree[ni];
    int shortestL = FindShortestIndex(cl, l, r, nl, m);
    int shortestR = FindShortestIndex(cr, l, r, m+1, nr);

    if((shortestL+1) * (shortestR+1) < 0)
    {
        if(shortestL < 0) return shortestR;
        if(shortestR < 0) return shortestL;
    }
    if(heights[shortestL] <= heights[shortestR]) return shortestL;
    else return shortestR;
}

ll F(int l, int r)
{
    if(l == r) return heights[l];
    if(l > r) return -1;

    int m = FindShortestIndex(0, l, r, 0, N-1);
    ll ret = max(F(l, m-1), F(m+1, r));
    ret = max(ret, heights[m] * (r-l+1));
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    heights = new ll[N];
    segtree = new ll[4*N];
    FOR(i, N) cin >> heights[i];
    SetSegTree(0, 0, N-1);

    cout << F(0, N - 1);

    return 0;
}