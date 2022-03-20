#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    bool visited = false;
    vector<int> linkedIndexes;
};

Node* nodes;

void DFS(int index)
{
    if(nodes[index].visited)
    {
        return;
    }
    
    nodes[index].visited = true;

    vector<int> &linked = nodes[index].linkedIndexes;

    for(int i=0 ; i<linked.size() ; ++i)
    {
        DFS(linked[i]);
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    Node n[N+1];
    nodes = n;

    for(int i=0 ; i<M ; ++i)
    {
        int a, b;
        cin >> a >> b;
        nodes[a].linkedIndexes.push_back(b);
        nodes[b].linkedIndexes.push_back(a);
    }

    int cnt = 0;
    for(int i=1 ; i<=N ; ++i)
    {
        if(!nodes[i].visited)
        {
            DFS(i);
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}