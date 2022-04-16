#include <iostream>
#include <vector>
#include <cmath>
#define ll long long int
using namespace std;

struct Node
{
    ll sum, l, r, cL, cR, lazy;
    Node() {}
    Node(ll _s, ll _l, ll _r, ll _cL, ll _cR)
    {
        sum = _s;
        l = _l;
        r = _r;
        cL = _cL;
        cR = _cR;
        lazy = 0;
    }
};

ll *numbers;
Node *segTree;

void Propagate(ll nI)
{
    Node *n = &segTree[nI];
    Node *nL = &segTree[n->cL];
    Node *nR = &segTree[n->cR];

    n->sum += (n->r - n->l + 1) * n->lazy;

    if (n->cL != n->cR)
    {
        nL->lazy += n->lazy;
        nR->lazy += n->lazy;
    }
    n->lazy = 0;
}

ll Sum(ll l, ll r, ll nI)
{
    Node *n = &segTree[nI];
    Propagate(nI);
    if (r < n->l || l > n->r) return 0;
    if (l <= n->l && r >= n->r) return n->sum;
    return Sum(l, r, n->cL) + Sum(l, r, n->cR);
}

void Modify(ll l, ll r, ll number, ll nI)
{
    Node *n = &segTree[nI];
    Node *nL = &segTree[n->cL];
    Node *nR = &segTree[n->cR];
    Propagate(nI);
    if (r < n->l || l > n->r) return;
    if (l <= n->l && r >= n->r)
    {
        n->sum += (n->r - n->l + 1) * number;
        if(n->l != n->r)
        {
            nL->lazy += number;
            nR->lazy += number;
        }
        return;
    }
    Modify(l, r, number, n->cL);
    Modify(l, r, number, n->cR);

    n->sum = nL->sum + nR->sum;
}

ll SetSegTree(ll l, ll r, ll nI)
{
    if (l == r)
    {
        segTree[nI] = Node(numbers[l], l, r, -1, -1);
        return numbers[l];
    }

    ll mid = (l + r) / 2;
    ll cR = (nI + 1) * 2;
    ll cL = cR - 1;
    ll sum = SetSegTree(l, mid, cL) + SetSegTree(mid + 1, r, cR);
    segTree[nI] = Node(sum, l, r, cL, cR);
    return segTree[nI].sum;
}

ll FindSize(ll N)
{
    ll ret = 1;
    while (ret < N) ret *= 2;
    return ret * 2;
}

void PrintSegTree(int treeSize)
{
    int level = 1;
    for(int i=0 ; i<treeSize-1 ; ++i)
    {
        cout << segTree[i].sum << ' ';
        if(i == pow(2, level) - 2)
        {
            cout << "\n";
            level++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M, K;
    cin >> N >> M >> K;
    ll treeSize = FindSize(N);
    numbers = new ll[N];
    segTree = new Node[treeSize];

    for (int i = 0; i < N; ++i) cin >> numbers[i];

    SetSegTree(0, N - 1, 0);

    while (M > 0 || K > 0)
    {
        short op; cin >> op;

        if (op == 1)
        {
            M--;
            ll l, r, c;
            cin >> l >> r >> c;
            Modify(l-1, r-1, c, 0);
            // PrintSegTree(treeSize);
        }
        else if (op == 2)
        {
            K--;
            ll a, b;
            cin >> a >> b;
            cout << Sum(a - 1, b - 1, 0) << "\n";
        }
    }

    return 0;
}