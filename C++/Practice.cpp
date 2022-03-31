#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node
{
    int parent = -1;
    vector<int> linked;
};

int N;
Node* nodes;

void SetParent(int p)
{
    vector<int> &linked = nodes[p].linked;

    for(int i=0 ; i<linked.size() ; ++i)
    {
        if(nodes[linked[i]].parent == -1)
        {
            nodes[linked[i]].parent = p;
            SetParent(linked[i]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    Node n[N+1];
    nodes = n;

    n[1].parent = 0;

    for(int i=2 ; i<=N ; ++i)
    {
        int a, b;
        cin >> a >> b;
        nodes[a].linked.push_back(b);
        nodes[b].linked.push_back(a);
    }

    SetParent(1);

    for(int i=2 ; i<=N ; ++i)
    {
        cout << nodes[i].parent << "\n";
    }

    return 0;
}