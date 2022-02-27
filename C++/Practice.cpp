#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    int coin[N];

    for(int i=0 ; i<N ; ++i)
    {
        cin >> coin[i];
    }

    int cnt = 0;
    for(int i=N-1 ; i>=0 ; --i)
    {
        cnt += K / coin[i];
        K %= coin[i];
    }

    cout << cnt;

    return 0;
}