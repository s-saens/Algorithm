#include <iostream>
#include <queue>
#include <algorithm>
#define FOR(i,e)for(int i=0;i<e;++i)
#define ll long long int
using namespace std;

// s, e : 점
// l, r : 구간

struct Node
{
    ll sum, l, r, cL, cR;
    Node() {}
    Node(ll _s, ll _l, ll _r, ll _cL, ll _cR)
    { sum = _s; l = _l; r = _r; cL = _cL; cR = _cR; }
};

Node *segTree;
ll *numbers, *answers, N, Q;

ll Sum(ll l, ll r, ll nI)
{
    Node *n = &segTree[nI];
    if(r < n->l || l > n->r) return 0;
    if(l <= n->l && r >= n->r) return n->sum;
    return Sum(l, r, n->cL) + Sum(l, r, n->cR);
}

ll Modify(ll i, ll number, ll nI) // 변화량 반환
{
    Node *n = &segTree[nI];
    if(n->l == n->r)
    {
        ll lastNumber = n->sum;
        n->sum = number;
        return number - lastNumber; // 변화량
    }

    ll nMid = (n->l + n->r)/2;
    ll delta = 0;
    if(i > nMid) delta = Modify(i, number, n->cR);
    else delta = Modify(i, number, n->cL);
    n->sum += delta;
    return delta;
}

ll SetSegTree(ll l, ll r, ll nI)
{
    if(l == r)
    {
        segTree[nI] = Node(numbers[l], l, r, -1, -1);
        return numbers[l];
    }

    ll mid = (l+r)/2;
    ll cR = (nI+1)*2;
    ll cL = cR - 1;
    ll sum = SetSegTree(l, mid, cL) + SetSegTree(mid+1, r, cR);
    segTree[nI] = Node(sum, l, r, cL, cR);
    return segTree[nI].sum;
}

ll FindSize(ll N)
{
    ll ret = 1;
    while(ret < N) ret *= 2;
    return ret * 2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    segTree = new Node[FindSize(N)];
    numbers = new ll[N];
    answers = new ll[N];

    FOR(i, N) cin >> numbers[i];

    SetSegTree(0, N-1, 0);

    FOR(k, Q)
    {
        ll s, e; cin >> s >> e; s--; e--;
        if(s > e) swap(s, e);
        answers[k] = Sum(s, e, 0);


        ll c, v; cin >> c >> v; c--;
        Modify(c, v, 0);
    }

    FOR(i, Q) cout << answers[i] << '\n';

    return 0;
}