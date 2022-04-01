#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int V, E, start;
int INF = 30000000;

struct Edge
{
    int destination = 0;
    int weight = 1;
};

struct Vertex
{
    vector<Edge> links;
};

struct EdgeCompare
{
    bool operator() (Edge& e1, Edge& e2)
    {
        return e1.weight > e2.weight;
    }
};

priority_queue<Edge, vector<Edge>, EdgeCompare> pq;
Vertex* vertexes;
int* answer;

void Dijkstra()
{
    while(!pq.empty())
    {
        Edge poppedEdge = pq.top(); pq.pop(); // 간선 선택
        Vertex v = vertexes[poppedEdge.destination]; // 현재 정점

        for(int i=0 ; i<v.links.size() ; ++i)
        {
            int d = v.links[i].destination;
            int w = v.links[i].weight + poppedEdge.weight;
            if (w <= answer[d])
            {
                v.links[i].weight = w;
                pq.push(v.links[i]);
                answer[d] = w;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E >> start;
    Vertex v[V+1];
    vertexes = v;
    int a[V+1];
    answer = a;
    for(int i=0 ; i<=V ; ++i)
    {
        if(i == start) answer[i] = 0;
        else answer[i] = INF;
    }

    for(int i=0 ; i<E ; ++i)
    {
        int s, d, w; // start -> destination : weight
        cin >> s >> d >> w;
        Edge e;
        e.destination = d;
        e.weight = w;

        vertexes[s].links.push_back(e);
    }

    Edge startEdge; // start->start : weigth 0
    startEdge.destination = start;
    startEdge.weight = 0 ;
    pq.push(startEdge);

    Dijkstra();

    for(int i=1 ; i<=V ; ++i)
    {
        if(answer[i] == INF) cout << "INF\n";
        else cout << answer[i] << "\n";
    }

    return 0;
}