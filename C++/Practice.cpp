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

int SQ(int num)
{
    return num * num;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    FOR(t, 0, T)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int C; cin >> C;

        int cnt = 0;

        FOR(c, 0, C)
        {
            int cx, cy, cr;
            cin >> cx >> cy >> cr;

            bool containsA = SQ(cx-x1) + SQ(cy-y1) <= SQ(cr);

            bool containsB = SQ(cx-x2) + SQ(cy-y2) <= SQ(cr);

            if(containsA != containsB) cnt++;
        }

        cout << cnt << "\n";
    }

    return 0;
}