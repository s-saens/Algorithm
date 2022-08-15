#include <iostream>
#define FOR(i,e)for(int i=0;i<e;++i)
#define ll long long int
using namespace std;

int N, *heights, *segtree;

void SetSegTree()
{
    // set segtree
}

int H(int m)
{
    // 인덱스 m부터 양쪽으로 퍼져나가며 인덱스 m을 포함하는 가장 큰 직사각형 찾아서 return
}

int F(int l, int r)
{
    // int m = 구간에서 가장 높이 작은 막대의 인덱스;
    // int ret = max(F(l, m), F(m+1, r));
    // ret = max(ret, H(m));
    // return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;

    while(N != 0)
    {
        heights = new int[N];
        segtree = new int[4*N];
        // SetSegTree();
        FOR(i, N) cin >> heights[i];

        cout << F(0, N-1) << '\n';
    }

    return 0;
}