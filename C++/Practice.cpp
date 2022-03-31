#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, E, K;
int INF = 2147483647;

struct Edge
{
    int next;
    int cost;
};

struct Node
{
    int index = 1;
    bool visited = false;
    vector<Edge> edges;
};

Node *nodes;
int *answer;

void Init()
{
    for (int i = 1; i <= N; ++i)
    {
        if(i == K) answer[i] = 0;
        else answer[i] = INF;

        nodes[i].index = i;

        Edge e;
        e.cost = 0;
        e.next = i;
        nodes[i].edges.push_back(e);
    }
}

void Dijkstra(int index)
{
    Init();

    int cummCost = 0;
    while(true)
    {
        vector<Edge>& edges = nodes[index].edges;

        Edge minEdge;
        minEdge.cost = INF;
        minEdge.next = -1;
        
        nodes[index].visited = true;

        for(int j=0 ; j<edges.size() ; ++j)
        {
            Edge e = edges[j];

            if(nodes[e.next].visited)
            {
                continue;
            }

            if(answer[e.next] > e.cost + cummCost)
            {
                answer[e.next] = e.cost + cummCost;
            }

            if(minEdge.cost > e.cost)
            {
                minEdge = e;
            }
        }

        if(minEdge.next == -1)
        {
            break;
        }

        index = minEdge.next;
        cummCost += minEdge.cost;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> E >> K;

    Node n[N + 1];
    nodes = n;
    int a[N + 1];
    answer = a;

    for (int i = 0; i < E; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if(a > N || b > N) continue;
        if(b == K) continue;
        
        Edge e;
        e.cost = c;
        e.next = b;

        nodes[a].edges.push_back(e);
    }

    Dijkstra(K);

    for (int i = 1; i <= N; ++i)
    {
        if (answer[i] == INF)
        {
            cout << "INF" << "\n";
            continue;
        }
        cout << answer[i] << "\n";
    }

    return 0;
}