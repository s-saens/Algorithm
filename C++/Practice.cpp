#include <iostream>
#include <queue>
#include <vector>

#define FOR(i, s, e) for (int i = s; i < e; ++i)

using namespace std;

struct Node
{
    int inCnt = 0; // 진입차수
    int number = 0;
    vector<int> nexts; // 다음 Node의 index 집합
};

Node *nodes;

struct CompareNodeInCnt
{
    bool operator()(int n1, int n2)
    {
        if (nodes[n1].inCnt > nodes[n2].inCnt)
        {
            return true;
        }
        else if (nodes[n1].inCnt == nodes[n2].inCnt)
        {
            return n1 > n2;
        }
        return false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    nodes = new Node[N];

    FOR(i, 0, N)
    nodes[i].number = i + 1;

    FOR(i, 0, M)
    {
        int n;
        cin >> n; // 보조 pd가 맡은 가수(Node)의 수

        if (n == 0)
            continue;

        int last;
        cin >> last;
        last--;

        FOR(j, 1, n)
        {
            int index;
            cin >> index;
            index--;
            nodes[last].nexts.push_back(index);
            nodes[index].inCnt++;
            last = index;
        }
    }

    priority_queue<int, vector<int>, CompareNodeInCnt> pq;

    FOR(i, 0, N)
    pq.push(i);

    vector<int> answer;

    while (!pq.empty())
    {
        Node node = nodes[pq.top()];

        if (node.inCnt > 0)
        {
            cout << 0;
            return 0;
        }

        answer.push_back(node.number);

        FOR(i, 0, node.nexts.size())
        {
            int next = node.nexts[i];
            nodes[next].inCnt--;
        }

        pq.pop();
    }

    if (answer.size() != N)
    {
        cout << 0;
        return 0;
    }
    FOR(i, 0, answer.size())
        cout << answer[i] << "\n";

    return 0;
}