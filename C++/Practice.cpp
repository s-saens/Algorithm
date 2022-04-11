#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int nodes[N][N];
    for(int i=0 ; i<N ; ++i)
        for(int j=0 ; j<N ; ++j)
            nodes[i][j] = i==j ? 0 : 50000;

    for(int i=0 ; i<M ; ++i)
    {
        int a, b;
        cin >> a >> b; a--; b--;
        nodes[a][b] = 1;
        nodes[b][a] = 1;
    }

    for(int i=0 ; i<N ; ++i)
        for(int s=0 ; s<N ; ++s)
            for(int e=0 ; e<N ; ++e)
                nodes[s][e] = min(nodes[s][e], nodes[s][i] + nodes[i][e]);

    int minimum = 50000;
    int minIndex = 0;
    for(int i=N-1 ; i>=0 ; --i)
    {
        int sum = 0;
        for(int j=0 ; j<N ; ++j)
        {
            sum += nodes[i][j];
        }
        
        if(minimum >= sum)
        {
            minimum = sum;
            minIndex = i+1;
        }
    }

    cout << minIndex;

    return 0;
}