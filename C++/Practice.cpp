#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, E, K;
int INF = 10;
int MAX = 30000000;

struct Edge
{
    int next;
    int cost;
};

struct Node
{
    int index;
    vector<Edge> nexts;
};

Node *nodes;
int *answer;
priority_queue<int, greater<int> > pq;

void Init()
{
    for(int i=0 ; i<N ; ++i)
    {
        pq.push(MAX);
    }
}

void Dijkstra(int start)
{
    Init();

    int index = start;

    for(int i=0 ; i<N ; ++i)
    {
        
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
        Edge e;
        e.cost = c;
        e.next = b;

        nodes[a].nexts.push_back(e);
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