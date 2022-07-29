#include <iostream>
#include <set>
#include <queue>
#define FOR(i, e) for (int i=0; i<e; ++i)
using namespace std;

struct Node
{
    int level = 0;
    int parent = -1;
    set<int> childrenIndexes;

    bool IsLeaf()
    {
        return childrenIndexes.size() == 0;
    }
};

Node* nodes;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    nodes = new Node[N];
    int rootIndex = 0;

    FOR(i, N)
    {
        int parentIndex; cin >> parentIndex;
        if(parentIndex < 0)
        {
            rootIndex = i;
            nodes[i].level = 0;
            continue;
        }
        nodes[i].level = nodes[parentIndex].level + 1;
        nodes[i].parent = parentIndex;
        nodes[parentIndex].childrenIndexes.insert(i);
    }

    int removing; cin >> removing;

    if(removing == rootIndex)
    {
        cout << 0;
        return 0;
    }

    nodes[nodes[removing].parent].childrenIndexes.erase(removing);

    queue<int> q;
    q.push(rootIndex);

    int answer = 0;

    while(!q.empty())
    {
        int f = q.front(); q.pop();

        if(nodes[f].IsLeaf())
        {
            answer++;
            continue;
        }

        set<int> &children = nodes[f].childrenIndexes;
        set<int>::iterator itr;

        for(itr = children.begin(); itr != children.end() ; itr++) q.push(*itr);
    }

    cout << answer;

    return 0;
}