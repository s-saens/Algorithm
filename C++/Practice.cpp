#include <bits/stdc++.h>
#define F(i, e) for (int i = 0; i < e; ++i)
using namespace std;

struct Tomato
{
    int i = 0, state = 0, days = 0;
};

int main()
{
    int rippedCnt = 0, emptyCnt = 0, totalCnt = 1, answer = 0;
    int s[11]; // 각 차원축의 크기
    int d[11] = {1}; // d[i] = 인접 인덱스 접근시 더하거나 뺄 값.
    // d[0] = 1, d[1] = s[0], d[2] = s[0] * s[1], ...

    F(i, 11) cin >> s[i];

    F(i, 11) if (i) d[i] = s[i - 1] * d[i - 1];

    Tomato tomatoes[totalCnt];

    queue<Tomato> q;

    F(i, totalCnt)
    {
        int state;
        cin >> state;
        tomatoes[i] = {i, state, 0};
        if (state > 0) q.push(tomatoes[i]);
        else if (state < 0) emptyCnt++;
    }

    while (!q.empty())
    {
        Tomato t = q.front();
        q.pop();
        rippedCnt++;
        answer = t.days;

        F(i, 22)
        {
            int k = i / 2;
            int positive = 1 - 2 * (i % 2); // i가 짝수면 1, 홀수면 -1
            int ni = t.i + positive * d[k]; // 다음 인덱스
            int nd = d[k] * s[k]; // = d[k+1]

            int m = t.i % nd;
            int nm = ni % nd;

            if (ni >= 0 && ni < totalCnt
            && positive * (nm - m) > 0
            && !tomatoes[ni].state)
            {
                tomatoes[ni] = {ni, 1, t.days + 1};
                q.push(tomatoes[ni]);
            }
        }
    }

    if (rippedCnt + emptyCnt - totalCnt || rippedCnt <= 0) answer = -1;

    cout << answer;
}