#include <iostream>
#include <queue>
#include <vector>

#define FOR(i, s, e) for(int i=s ; i<e ; ++i)

using namespace std;

struct Node
{
    int inCnt = 0; // 진입차수
    int number = 0;
    vector<int> nexts; // 다음 Node의 index 집합
};

Node* nodes;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    nodes = new Node[N];

    FOR(i, 0, N) nodes[i].number = i+1;

    FOR(i, 0, M)
    {
        int a, b; cin >> a >> b;
        a--; b--;

        nodes[a].nexts.push_back(b);
        nodes[b].inCnt++;
    }

    queue<int> q;
    vector<int> answer;

    FOR(i, 0, N) if (nodes[i].inCnt == 0) q.push(i);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        answer.push_back(cur+1);

        FOR(i, 0, nodes[cur].nexts.size())
        {
            int next = nodes[cur].nexts[i];
            nodes[next].inCnt--;
            if (nodes[next].inCnt == 0)
            {
                q.push(next);
            }
        }
    }

    // if(answer.size() < N) cout << 0;
    FOR(i, 0, answer.size()) cout << answer[i] << " ";

    return 0;
}