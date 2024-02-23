#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define FOR(i,e) for(int i=0 ; i<e ; ++i)
#define MAX 2100000000

using namespace std;

struct Route
{
    int node, cost;
};

struct RouteCompare
{
    bool operator() (const Route& r1, const Route& r2) const
    {
        return r1.cost > r2.cost;
    }
};

struct Node
{
    vector<Route> routes;
};

int N, M, X;

vector<int> dijkstra(Node* nodes)
{
    priority_queue<Route, vector<Route>, RouteCompare> pq;
    pq.push({X-1, 0});

    vector<int> dist(N, MAX);

    while(!pq.empty())
    {
        Route r = pq.top(); pq.pop();

        for(const Route& nextRoute : nodes[r.node].routes)
        {
            int n = nextRoute.node ; int c = nextRoute.cost;
            int newCost = r.cost + c;
            if(newCost <= dist[n])
            {
                dist[n] = newCost;
                pq.push({n, newCost});
            }
        }
    }

    return dist;
}


int main()
{
    cin >> N >> M >> X;
    Node nodes1[N];
    Node nodes2[N];

    FOR(i, M)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        from--; to--;

        nodes1[from].routes.push_back({to, cost});
        nodes2[to].routes.push_back({from, cost});
    }

    vector<int> d1 = dijkstra(nodes1);
    vector<int> d2 = dijkstra(nodes2);

    int maximum = 0;

    FOR(i, N) if(i != X-1) maximum = max(d1[i] + d2[i], maximum);

    cout << maximum;

    return 0;
}