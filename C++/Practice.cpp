#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define ll long long int
#define FOR(i, s, e) for(int i=s ; i<e ; ++i)

using namespace std;

class Edge
{
public:
    int next;
    int weight;

    Edge(int n, int w)
    {
        next = n;
        weight = w;
    }
};

struct CompareEdges
{
    bool operator() (Edge& e1, Edge& e2)
    {
        return e1.weight > e2.weight;
    }
};

struct Node
{
    vector<Edge> edges;
    bool visited = false;
};

Node* nodes;
priority_queue<Edge, vector<Edge>, CompareEdges> edges;

void Insert(int n)
{
    nodes[n].visited = true;
    FOR(i, 0, nodes[n].edges.size())
    {
        Edge* e = &nodes[n].edges[i];
        if(!nodes[e->next].visited) edges.push(*e);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    scanf("%d %d", &V, &E);
    nodes = new Node[V];

    FOR(e, 0, E)
    {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        a--; b--;
        nodes[a].edges.push_back(Edge(b, w));
        nodes[b].edges.push_back(Edge(a, w));
    }

    Insert(0);

    ll sum = 0;

    FOR(v, 1, V)
    {
        Edge e = edges.top(); edges.pop();

        while(nodes[e.next].visited)
        {
            e = edges.top(); edges.pop();
        }

        sum += e.weight;
        Insert(e.next);
    }

    printf("%lld", sum);

    return 0;
}