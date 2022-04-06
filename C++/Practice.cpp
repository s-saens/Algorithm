#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int cnt = 1;
    int sum = 0;
    int r = N/2 + 1;

    for(int l=r ; l>=1 ; --l)
    {
        sum += l;
        if(sum >= N)
        {
            if(sum == N) cnt++;
            sum -= r;
            r--;
        }
    }

    if(N <= 2)
    {
        cnt = 1;
    }

    cout << cnt;

    return 0;
}