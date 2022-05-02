#include <iostream>
#include <algorithm>
#define FOR(i, s, e) for(int i=s ; i<e ; ++i)

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int MAX = 1000000000;

    int N, S;
    cin >> N >> S;

    int sums[N+1];
    sums[0] = 0;

    cin >> sums[1];

    FOR(i, 2, N+1)
    {
        int number;
        cin >> number;
        sums[i] = sums[i-1] + number;
    }

    int l = 1; // inclusive
    int r = 1; // inclusive

    int minRL = MAX;
    
    while(l <= r && r <= N && l >= 0)
    {
        int sum = sums[r] - sums[l-1];

        // cout << '>' << l << ',' << r << ':' << sum << " ... " << minRL << "\n";

        if(sum < S) r++;
        else if(sum >= S)
        {
            minRL = min(minRL, r - l);
            l++;
        }
    }

    if(minRL == MAX) cout << 0;
    else cout << minRL + 1;

    return 0;
}