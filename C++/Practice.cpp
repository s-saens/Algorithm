#include <iostream>
#include <vector>
#include <queue>

#define FOR(i, s, e) for(int i=s ; i<e ; ++i)

using namespace std;

struct Node 
{
    vector<int> nexts;
    int inCnt = 0;
};

Node* nodes;

void Connect(int a, int b)
{
    nodes[a].nexts.push_back(b);
    nodes[b].inCnt++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; cin >> N >> M;
    nodes = new Node[N];

    int startNode = 0;

    FOR(i, 0, M) 
    {
        int a, b; cin >> a >> b;
        a--; b--;

        Connect(a, b);
    }

    priority_queue<int, vector<int>, greater<int> > pq;
    vector<int> answers;

    FOR(i, 0, N) if (nodes[i].inCnt == 0) pq.push(i);

    while(!pq.empty())
    {
        int now = pq.top(); pq.pop();
        answers.push_back(now+1);

        FOR(i, 0, nodes[now].nexts.size())
        {
            int next = nodes[now].nexts[i];
            nodes[next].inCnt--;
            if(nodes[next].inCnt == 0) pq.push(next);
        }
    }

    FOR(i, 0, N) cout << answers[i] << ' ';

    return 0;
}