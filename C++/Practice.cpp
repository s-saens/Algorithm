#include <iostream>
#include <vector>
#include <cmath>
#define FOR(i, e) for(int i=0; i<e ; ++i)
#define ll long long int
#define MAX 2000000
using namespace std;

ll N, M, numbers[MAX], segtree[4*MAX];

ll SetSegtree(int index, int nowL, int nowR)
{
    if(nowL == nowR)
    {
        segtree[index] = numbers[nowL];
        return numbers[nowL];
    }

    int middle = (nowL + nowR) / 2;
    int nextIndexR = 2 * (index + 1);
    int nextIndexL = nextIndexR - 1;
    segtree[index] = SetSegtree(nextIndexL, nowL, middle) + SetSegtree(nextIndexR, middle + 1, nowR);
    return segtree[index];
}

ll Sum(int index, int nowL, int nowR, int targetL, int targetR)
{
    if(targetR < nowL || nowR < targetL) return 0;
    if(targetL <= nowL && nowR <= targetR) return segtree[index];

    int middle = (nowL + nowR) / 2;
    int nextIndexR = 2*(index + 1);
    int nextIndexL = nextIndexR - 1;
    ll sum = Sum(nextIndexL, nowL, middle, targetL, targetR) + Sum(nextIndexR, middle + 1, nowR, targetL, targetR);
    return sum;
}

void Modify(int index, int nowL, int nowR, int targetIndex, ll diff)
{
    if(nowL > targetIndex || nowR < targetIndex) return;

    segtree[index] += diff;

    if(nowL == nowR) return;

    int middle = (nowL + nowR) / 2;
    int nextIndexR = 2 * (index + 1);
    int nextIndexL = nextIndexR - 1;
    if(targetIndex <= middle) Modify(nextIndexL, nowL, middle, targetIndex, diff);
    else Modify(nextIndexR, middle + 1, nowR, targetIndex, diff);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    vector<ll> answers;

    FOR(i, N) numbers[i] = 0;
    SetSegtree(0, 0, N-1);

    FOR(i, M)
    {
        int op; cin >> op;
        ll a, b; cin >> a >> b;
        if(op == 0)
        {
            a--; b--;
            if(a > b) swap(a, b);
            answers.push_back(Sum(0, 0, N-1, a, b));
        }
        else if(op == 1)
        {
            a--;
            ll adding = b - numbers[a];
            numbers[a] = b;
            Modify(0, 0, N-1, a, adding);
        }
    }

    int l = answers.size();
    FOR(i, l) cout << answers[i] << '\n';

    return 0;
}