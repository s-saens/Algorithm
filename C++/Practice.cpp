#include <iostream>
#include <algorithm>
#define FOR(i, s, e) for(int i=s ; i<e ; ++i)

using namespace std;

int* nexts;
bool* visited;
bool* done;

int cnt = 0;

void Set(int n)
{
    visited[n] = true;
    int next = nexts[n];
    
    if(!visited[next]) Set(next);
    else if(!done[next])
    {
        for(int i=next ; i!=n ; i=nexts[i]) cnt++;
        cnt++;
    }

    done[n] = true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    int answers[T];

    FOR(t, 0, T)
    {
        cnt = 0;
        int N; cin >> N;
        nexts = new int[N];
        visited = new bool[N];
        done = new bool[N];

        FOR(i, 0, N)
        {
            int n; cin >> n;
            nexts[i] = n - 1;
            visited[i] = 0;
            done[i] = 0;
        }

        FOR(i, 0, N) if(!visited[i]) Set(i);

        answers[t] = N - cnt;
    }

    FOR(t, 0, T) cout << answers[t] << "\n";


    return 0;
}