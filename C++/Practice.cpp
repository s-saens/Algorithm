#include <iostream>
#include <queue>
using namespace std;

int K;

int t[100001] = {-1};

int F(int N)
{
    queue<int> q;
    q.push(N);
    t[N] = 0;

    while(!q.empty())
    {
        int f = q.front(); q.pop();
        if(f == K) return t[f];

        if(f+1 <= 100000 && f+1 >= 0 && t[f+1] == -1) { q.push(f+1); t[f+1] = t[f]+1; }
        if(f-1 <= 100000 && f-1 >= 0 && t[f-1] == -1) { q.push(f-1); t[f-1] = t[f]+1; }
        if(f*2 <= 100000 && f*2 > 0 && t[f*2] == -1) { q.push(f*2); t[f*2] = t[f]+1; }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0 ; i<100001 ; ++i) t[i] = -1;

    int N;
    cin >> N >> K;

    cout << F(N);

    return 0;
}