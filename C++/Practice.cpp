#include <iostream>
#include <vector>
#define FOR(i,s,e) for(int i=s ; i<e ; ++i)
using namespace std;

int N, M, *p, *d;
bool *v;
vector<int> *links;

void input()
{
    FOR(i, 1, N)
    {
        int a, b; cin >> a >> b;
        links[a].push_back(b);
        links[b].push_back(a);
    }

    FOR(i, 0, N+1) p[i] = -1, d[i] = 0, v[i] = false;
}

void updateDepth(int i, int depth)
{
    v[i] = true;
    for(int n : links[i])
    {
        if(v[n]) continue;

        p[n] = i;
        d[n] = depth + 1;

        updateDepth(n, depth + 1);
    }
}

int lca(int a, int b)
{
    while(d[a] != d[b])
    {
        if(d[a] > d[b]) a = p[a];
        else b = p[b];
    }
    
    while(a != b)
    {
        a = p[a];
        b = p[b];
    }

    return a;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    v = new bool[N+1]; p = new int[N+1]; d = new int[N+1], links = new vector<int>[N+1];

    input();

    updateDepth(1, 0);

    cin >> M;
    while(M--)
    {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    
    return 0;
}