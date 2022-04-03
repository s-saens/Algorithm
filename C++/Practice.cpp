#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    short num = 0;
    int dist = 0;    // distance from root node
    short level = 0; // = parents.size();
    vector<short> parents;
    vector<short> children;
};

Node *nodes;

int FindSameParent(int a, int b)
{
    int longer;  // has more parents
    int shorter; // has less parents
    if (nodes[a].level > nodes[b].level)
    {
        longer = a;
        shorter = b;
    }
    else
    {
        longer = b;
        shorter = a;
    }

    int i;
    for (i = 0; i < nodes[shorter].level; ++i)
    {
        if (nodes[shorter].parents[i] != nodes[longer].parents[i])
        {
            return nodes[shorter].parents[i - 1];
        }
    }

    return nodes[shorter].parents[i - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    Node n[N + 1];
    nodes = n;

    vector<short> leaves;

    for (int i = 0; i <= N; ++i)
    {
        nodes[i].num = i;
    }

    for (int i = 1; i < N; ++i)
    {
        int p, c, d;
        cin >> p >> c >> d;
        nodes[c].dist = d + nodes[p].dist;
        nodes[c].level = nodes[p].level + 1;
        nodes[c].parents = nodes[p].parents;
        nodes[c].parents.push_back(p);
        nodes[p].children.push_back(c);
    }

    int maxDistNode = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (nodes[maxDistNode].dist < nodes[i].dist)
        {
            maxDistNode = i;
        }
        if (nodes[i].children.empty())
        {
            leaves.push_back(i);
        }
    }

    int maximum = 0;
    for (int i = 0; i < leaves.size(); ++i)
    {
        if (nodes[leaves[i]].num == nodes[maxDistNode].num)
            continue;

        int distance = nodes[leaves[i]].dist + nodes[maxDistNode].dist - (2 * nodes[FindSameParent(leaves[i], maxDistNode)].dist);
        maximum = max(maximum, distance);
    }

    cout << maximum;

    return 0;
}