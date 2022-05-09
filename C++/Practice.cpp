#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define FOR(i, s, e) for(int i=s ; i<e ; ++i)
#define ll long long int

using namespace std;

int N, M;

struct Edge
{
    int to = 0;
    ll weight = 0;
    Edge(int t, int w)
    {
        to = t;
        weight = w;
    }
};

struct Node
{
    vector<Edge> edges;
    bool visited = false;

    Node() {}
};

struct CompareEdges
{
    bool operator() (Edge& e1, Edge& e2)
    {
        return e1.weight > e2.weight;
    }
};

Node* nodes;
priority_queue<Edge, vector<Edge>, CompareEdges> edges;

void Insert(int n)
{
    nodes[n].visited = true;
    FOR(i, 0, nodes[n].edges.size())
    {
        Edge* e = &nodes[n].edges[i];
        if(!nodes[e->to].visited) edges.push(*e);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    nodes = new Node[N];

    FOR(i, 0, M)
    {
        int a, b, w; cin >> a >> b >> w;
        a--; b--;
        nodes[a].edges.push_back(Edge(b, w));
        nodes[b].edges.push_back(Edge(a, w));
    }

    ll sum = 0;
    ll maxW = 0;

    Insert(0);

    FOR(v, 1, N)
    {
        Edge e = edges.top(); edges.pop();
        while(nodes[e.to].visited) { e = edges.top(); edges.pop(); }

        sum += e.weight;
        maxW = max(maxW, e.weight);
        Insert(e.to);
    }

    cout << sum - maxW;

    return 0;
}