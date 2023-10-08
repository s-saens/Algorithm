#include <iostream>
#include <algorithm>
#include <vector>
#define FOR(i, s, e) for(int i=s ; i<e; ++i)

using namespace std;

struct Link
{
    Link(int t, int l)
    {
        to = t;
        length = l;
    }

    int to;
    int length;
};

struct Node
{
    vector<Link> links;
};

Node* nodes;
bool* visited;
int N;

int dfs(int nIndex)
{
    int len = 0;
    visited[nIndex] = true;

    vector<Link> &links = nodes[nIndex].links;

    FOR(i, 0, links.size())
    {
        Link l = links[i];
        if(!visited[l.to])
        {
            len = max(len, dfs(l.to) + l.length);
            visited[l.to] = true;
        }
    }

    return len;
}

void init()
{
    FOR(i, 0, N) visited[i] = false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    nodes = new Node[N];
    visited = new bool[N];

    FOR(i, 0, N-1)
    {
        int s, t, l; cin >> s >> t >> l;
        nodes[s-1].links.push_back(Link(t-1, l));
        nodes[t-1].links.push_back(Link(s-1, l));
    }
    
    int answer = 0;

    vector<int> leafNodes;

    FOR(i, 0, N) if(nodes[i].links.size() == 1) leafNodes.push_back(i);

    FOR(i, 0, leafNodes.size())
    {
        int ni = leafNodes[i];
        init();
        
        answer = max(answer, dfs(ni));
    }

    cout << answer << endl;

    return 0;
}