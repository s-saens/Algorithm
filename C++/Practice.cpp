#include <iostream>
#include <vector>
#include <algorithm>

#define FOR(i, s, e) for(int i=s ; i<e; ++i)

// n = number
// s = segtree
// i = index
// l = left
// r = right
// c_ = child
// m = middle

// ex1: nir = number index right
// ex2: c_sil = child segtree index left

using namespace std;

int MAX = 1000000001;

int N;

struct Node
{
    int value, nil, nir;
    Node() {}
    Node(int v, int l, int r)
    { value = v; nil = l; nir = r; }
};

// segtree data-oriented properties
Node* segtree;
int* numbers;

int initSegtree(int si, int nil, int nir)
{
    if(nil == nir)
    {
        int number = numbers[nil];
        segtree[si] = Node(number, nil, nir);
        return number;
    }

    int nim = (nil+nir) / 2;

    int c_sir = (si+1) * 2;
    int c_sil = c_sir - 1; // child index left

    int ret = min(initSegtree(c_sil, nil, nim), initSegtree(c_sir, nim+1, nir));

    segtree[si] = Node(ret, nil, nir);

    return ret;
}
int query(int si, int qnil, int qnir) // segtree index, index left, index right
{
    if(qnil == qnir) return numbers[qnir];

    Node* seg = segtree + si;
    int sm = (seg->nil + seg->nir) / 2;

    int c_sir = (si+1) * 2;
    int c_sil = c_sir - 1; // child index left
    
    if(seg->nir < qnil || seg->nil > qnir) return MAX; // 쿼리범위가 세그먼트 범위를 벗어난 경우
    if(qnil <= seg->nil && seg->nir <= qnir) return seg->value; // 쿼리범위가 세그먼트 범위를 포함하는 경우

    return min(query(c_sil, qnil, qnir), query(c_sir, qnil, qnir));
}

// int query(int si, int qnil, int qnir) // segtree index, index left, index right
// {
//     if(qnil == qnir) return numbers[qnir];

//     int ret = MAX;

//     Node seg = segtree[si];
//     int sm = (seg.nil + seg.nir) / 2;

//     int c_sir = (si+1) * 2;
//     int c_sil = c_sir - 1; // child index left
    

//     if(qnil <= sm) ret = min(ret, query(c_sil, qnil, min(sm, qnir)));
//     if(qnir > sm) ret = min(ret, query(c_sir, max(sm+1, qnil), qnir));

//     return ret;
// }

int update(int si, int ni, int nv)
{
    Node* seg = segtree + si;

    if(seg->nil == seg->nir)
    {
        seg->value = nv;
        numbers[ni] = nv;
        return nv;
    }

    int sm = (seg->nil + seg->nir) / 2;

    int c_sir = (si+1) * 2;
    int c_sil = c_sir - 1; // child index left

    int ret;

    if(ni <= sm) ret = min(update(c_sil, ni, nv), query(c_sir, sm+1, seg->nir));
    else ret = min(update(c_sir, ni, nv), query(c_sil, seg->nil, sm));

    seg->value = ret;
    return ret;
}

void printSegtree()
{
    cout << '\n';
    int k = 1, j = 1;
    FOR(i, 0, 4*N)
    {
        cout << segtree[i].value << ' ';
        if(j == k)
        {
            cout << '\n',
            j = 1;
            k *= 2;
        }
        else j++;
    }
    cout << "\n\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    numbers = new int[N];

    FOR(i, 0, N) cin >> numbers[i];
    

    segtree = new Node[4*N];

    initSegtree(0, 0, N-1);

    int K; cin >> K;

    vector<int> answers;

    // printSegtree();

    FOR(i, 0, K)
    {
        int op, a, b;
        cin >> op >> a >> b; a--;

        if(op == 1)
        {
            update(0, a, b);
            // printSegtree();
        }
        if(op == 2) answers.push_back(query(0, a, b-1));

    }

    int len = answers.size();
    FOR(i, 0, len) cout << answers[i] << '\n';

    return 0;
}