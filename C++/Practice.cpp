#include <iostream>
#include <cmath>
#include <algorithm>
#define FOR(i,s,e) for(int i=s ; i<e ; ++i)
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    int ropes[N];

    FOR(i, 0, N)
    {
        cin >> ropes[i];
    }

    sort(ropes, ropes+N);

    int M = 0;

    FOR(i, 0, N)
    {
        int cnt = N-i;
        int w = cnt * ropes[i];
        M = max(M, w);
    }

    cout << M ;

    return 0;
}