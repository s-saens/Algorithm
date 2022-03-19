#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    bool visited = false;
    vector<int> linkedNodeIndexes;
};

int C, P;
int cnt = 0;

Node* nodes;

void DFS(int index)
{
    if(nodes[index].visited)
    {
        return;
    }
    nodes[index].visited = true;
    cnt++;

    vector<int>& linked = nodes[index].linkedNodeIndexes;

    for(int i=0 ; i<linked.size() ; ++i)
    {
        if(!nodes[linked[i]].visited)
        {
            DFS(linked[i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> C >> P;
    Node n[C+1];
    nodes = n;

    for(int i=0 ; i<P ; ++i)
    {
        int a, b;
        cin >> a >> b;

        nodes[a].linkedNodeIndexes.push_back(b);
        nodes[b].linkedNodeIndexes.push_back(a);
    }

    DFS(1);

    cout << cnt-1;

    return 0;
}