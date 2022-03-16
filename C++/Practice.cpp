#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct Node
{
    bool visited;
    vector<int> linkedNodeIndex;
};

Node nodes[1001];

void InitiateFlag()
{
    for(int i=0 ; i<1001 ; ++i)
    {
        nodes[i].visited = false;
    }
}

void DFS(int nodeIndex)
{
    vector<int>& linked = nodes[nodeIndex].linkedNodeIndex;

    nodes[nodeIndex].visited = true;

    cout << nodeIndex << ' ';

    for(int i=0 ; i<linked.size() ; ++i)
    {
        if(!nodes[linked[i]].visited)
        {
            DFS(linked[i]);
        }
    }
    
}

queue<int> q;

void BFS(int nodeIndex)
{
    q.push(nodeIndex);
    while(q.size() > 0)
    {
        int pop = q.front(); q.pop();
        if(nodes[pop].visited)
        {
            continue;
        }
        cout << pop << ' ';
        nodes[pop].visited = true;
        vector<int>& linked = nodes[pop].linkedNodeIndex;
        for(int i=0 ; i<linked.size() ; ++i)
        {
            if(!nodes[linked[i]].visited)
            {
                q.push(linked[i]);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;

    for(int i=0 ; i<M ; ++i)
    {
        int a, b;
        cin >> a >> b;
        nodes[a].linkedNodeIndex.push_back(b);
        nodes[b].linkedNodeIndex.push_back(a);
    }

    for(int i=0 ; i<1001 ; ++i)
    {
        vector<int>& linked = nodes[i].linkedNodeIndex;
        sort(linked.begin(), linked.end());
    }

    InitiateFlag();

    DFS(V);
    cout << "\n";

    InitiateFlag();

    BFS(V);

    return 0;
}