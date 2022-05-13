#include <iostream>
#include <queue>
#include <cstring>
#include <string>

#define FOR(i, s, e) for (int i = s; i < e; ++i)

using namespace std;

char c[4] = {'D', 'S', 'L', 'R'};

struct Snapshot
{
    int number;
    string history;

    Snapshot(int n, string h)
    {
        number = n;
        history = h;
    }
};

int D(int number)
{
    return (number * 2) % 10000;
}

int S(int number)
{
    return number == 0 ? 9999 : number-1;
}

int L(int number)
{
    return (number % 1000) * 10 + (number / 1000);
}

int R(int number)
{
    return number / 10 + (number % 10) * 1000;
}

int Operate(int op, int num)
{
    switch (op)
    {
        case 0: return D(num);
        case 1: return S(num);
        case 2: return L(num);
        case 3: return R(num);
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;

    FOR(t, 0, T)
    {
        bool visited[10000];
        memset(visited, 0, sizeof(visited));

        int start, target;
        cin >> start >> target;

        queue<Snapshot> q1;

        string s;

        FOR(i, 0, 4) q1.push(Snapshot(Operate(i, start), s + c[i]));

        visited[start] = true;

        string answer;

        while(!q1.empty())
        {
            Snapshot ss = q1.front(); q1.pop();

            visited[ss.number] = true;

            if(ss.number == target)
            {
                answer = ss.history;
                break;
            }

            FOR(i, 0, 4)
            {
                int operated = Operate(i, ss.number);
                if(!visited[operated])
                {
                    visited[operated] = true;
                    q1.push(Snapshot(operated, ss.history + c[i]));
                }
            }
        }
        
        cout << answer << "\n";
    }

    return 0;
}