#include <iostream>
#include <vector>
#include <queue>
#define FOR(i, e) for (int i=0; i<e; ++i)
using namespace std;

struct Node
{
    char visited = -1;
    bool checked = false;

    vector<int> links;
};

struct Snapshot
{
    int n, d;
    Snapshot(int _n, int _d) { n = _n; d = _d; }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M; cin >> N >> M;
    Node nodes[N];

    FOR(i, M)
    {
        int a, b; cin >> a >> b; a--; b--;
        nodes[a].links.push_back(b);
        nodes[b].links.push_back(a);
    }
    
    int sum = 0;
    char nowSign = 1;

    FOR(k, N)
    {
        queue<Snapshot> q;
        q.push(Snapshot(k, 1));

        if(nodes[k].checked) continue;

        nodes[k].checked = true;
        nodes[k].visited = nowSign;

        while(!q.empty())
        {
            Snapshot s = q.front(); q.pop();

            vector<int>& links = nodes[s.n].links;

            FOR(i, links.size())
            {
                if(nodes[links[i]].visited == nowSign) continue;
                if(!nodes[links[i]].checked) sum += s.d;
                nodes[links[i]].visited = nowSign;
                q.push(Snapshot(links[i], s.d+1));
            }
        }

        nowSign *= -1;
    }

    cout << sum;

    return 0;
}