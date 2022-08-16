#include <iostream>
#include <algorithm>
#define FOR(i,e)for(int i=0;i<e;++i)
#define MAX 1000000000
#define ll long long int
using namespace std;

ll N, M, *numbers, *segtree, *answers;

int SetSegtree(int ni, int nl, int nr)
{
    if(nl == nr)
    {
        segtree[ni] = numbers[nl];
        return numbers[nl];
    }

    int nm = (nl+nr)/2;
    int cr = (ni+1)*2;
    int cl = cr - 1;

    segtree[ni] = min(SetSegtree(cl, nl, nm), SetSegtree(cr, nm+1, nr));

    return segtree[ni];
}

int FindMinimum(int ni, int l, int r, int nl, int nr)
{
    int nm = (nl+nr)/2;
    int cr = (ni+1)*2;
    int cl = cr - 1;
    if(l > nr || r < nl) return MAX;
    if(l <= nl && nr <= r) return segtree[ni];
    return min(FindMinimum(cl, l, r, nl, nm), FindMinimum(cr, l, r, nm+1, nr));
}

void Print()
{
    int s = 0;
    int r = 1;
    while(s < 4*N-1)
    {
        FOR(i, r)
        {
            cout << segtree[s] << ' ';
            s++;
        }
        cout << '\n';
        r *= 2;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    numbers = new ll[N];
    segtree = new ll[4*N];
    answers = new ll[M];

    FOR(i, N) cin >> numbers[i];

    SetSegtree(0, 0, N-1);

    FOR(i, M)
    {
        int l, r; cin >> l >> r; l--; r--;
        if(l > r) swap(l, r);
        answers[i] = FindMinimum(0, l, r, 0, N-1);
    }

    FOR(i, M) cout << answers[i] << '\n';

    return 0;
}