#include <stdio.h>
#include <set>
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

    bool operator < (const Edge& e) const
    {
        return weight < e.weight;
    }
};

struct Node
{
    vector<Edge> edges;
    bool visited = false;
};

Node* nodes;
set<Edge> edges;

void Insert(int n)
{
    nodes[n].visited = true;
    FOR(i, 0, nodes[n].edges.size()) edges.insert(nodes[n].edges[i]);
}

int main()
{
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

    int nowNode = 0;
    Insert(nowNode);

    ll sum = 0;

    FOR(v, 1, V)
    {
        Edge e = *(edges.begin());
        edges.erase(edges.begin());
        while(nodes[e.next].visited)
        {
            e = *(edges.begin());
            edges.erase(edges.begin());
        }
        sum += e.weight;
        nowNode = e.next;
        Insert(nowNode);
    }

    printf("%lld", sum);

    return 0;
}