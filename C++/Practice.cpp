#include <iostream>
#include <vector>
#define ll long long int
using namespace std;

struct Node
{
    ll sum, l, r, cL, cR;
    Node() {}
    Node(ll _s, ll _l, ll _r, ll _cL, ll _cR)
    { sum = _s; l = _l; r = _r; cL = _cL; cR = _cR; }
};

ll* numbers;
Node* segTree;

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
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M, K; cin >> N >> M >> K;
    ll treeSize = FindSize(N);
    numbers = new ll[N];
    segTree = new Node[treeSize];
    
    for(int i=0 ; i<N ; ++i) cin >> numbers[i];

    SetSegTree(0, N-1, 0);

    while(M > 0 || K > 0)
    {
        short op;
        ll a, b;
        cin >> op >> a >> b;

        if(op == 1)
        {
            M--;
            Modify(a-1, b, 0);
        }
        else if(op == 2)
        {
            K--;
            cout << Sum(a-1, b-1, 0) << "\n";
        }
    }

    return 0;
}