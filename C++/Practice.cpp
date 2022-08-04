#include <iostream>
#include <vector>
#define FOR(i,s,e)for(int i=s;i<e;++i)
#define ll
using namespace std;

struct Node
{
    int praised=0, parent=-2;
};

int N, M;
Node* nodes;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    nodes = new Node[N];

    FOR(i,0,N)
    {
        int u; cin >> u; u--;
        nodes[i].parent = u;
    }

    FOR(i,0,M)
    {
        int n, p; cin >> n >> p; n--;
        nodes[n].praised += p;
    }

    cout << nodes[0].praised << ' ';
    FOR(i,1,N)
    {
        nodes[i].praised = nodes[i].praised + nodes[nodes[i].parent].praised;
        cout << nodes[i].praised << ' ';
    }

    return 0;
}