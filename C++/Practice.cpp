#include <iostream>
#include <algorithm>
#define FOR(i, s, e) for(int i=s ; i<e ; ++i)
#define MIN 0
#define MAX 1000000001
using namespace std;

struct Pair
{
    int minimum, maximum;
    Pair() {}
    Pair(int m, int M)
    {
        minimum = m;
        maximum = M;
    }
};

struct Node
{
    Pair minmax;
    int left, right;
    Node *childL, *childR;

    Node() {}
    Node(Pair p, int l, int r, Node* cL, Node* cR)
    {
        minmax = p;
        left = l;
        right = r;
        childL = cL;
        childR = cR;
    }
};

int* numbers;
Node* segtree;

int FindSize(int N)
{
    int ret = 1;
    while (ret < N) ret *= 2;
    return ret * 2;
}

int FindMin(int l, int r)
{
    int minimum = numbers[l];
    FOR(i, l+1, r) minimum = min(minimum, numbers[i]);
    return minimum;
}

Pair Query(Node* node, int l, int r)
{
    if(r < node->left || l > node->right) return Pair(MAX, MIN);
    if(l <= node->left && r >= node->right) return node->minmax;
    Pair leftMinmax = Query(node->childL, l, r);
    Pair rightMinmax = Query(node->childR, l, r);
    int minimum = min(leftMinmax.minimum, rightMinmax.minimum);
    int maximum = max(leftMinmax.maximum, rightMinmax.maximum);
    return Pair(minimum, maximum);
}

Pair SetSegtree(int nodeIndex, int l, int r)
{
    if(l == r)
    {
        int num = numbers[l];
        Pair p = Pair(num, num);
        segtree[nodeIndex] = Node(p, l, r, segtree+nodeIndex, segtree+nodeIndex);
        return p;
    }

    int mid = (l+r)/2;
    int rIndex = (nodeIndex+1) * 2;
    int lIndex = rIndex - 1;
    Pair leftMinmax = SetSegtree(lIndex, l, mid);
    Pair rightMinmax = SetSegtree(rIndex, mid+1, r);
    int minimum = min(leftMinmax.minimum, rightMinmax.minimum);
    int maximum = max(leftMinmax.maximum, rightMinmax.maximum);

    Pair minmax = Pair(minimum, maximum);

    segtree[nodeIndex] = Node(minmax, l, r, segtree+lIndex, segtree+rIndex);

    return minmax;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    numbers = new int[N];
    segtree = new Node[FindSize(N)];

    FOR(i, 0, N) cin >> numbers[i];

    SetSegtree(0, 0, N);

    FOR(i, 0, M)
    {
        int l, r; cin >> l >> r; l--; r--;
        Pair p = Query(segtree, l, r);
        cout << p.minimum << ' ' << p.maximum << '\n';
    }

    return 0;
}