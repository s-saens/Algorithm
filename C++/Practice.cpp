#include <iostream>
#define FOR(i,s,e) for(int i=s; i<e ; ++i)
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ca[46], cb[46];
    ca[1] = 0;
    cb[1] = 1;

    int K; cin >> K;
    FOR(i,2,K+1)
    {
        ca[i] = cb[i-1];
        cb[i] = cb[i-1] + ca[i-1];
    }

    cout << ca[K] << ' ' << cb[K];

    return 0;
}