#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int L;
    cin >> L;


    int S[L+1];
    S[0] = 0;
    for(int i=1 ; i<L+1 ; ++i)
    {
        cin >> S[i];
    }
    int n;
    cin >> n;

    sort(S, S+L+1);


    int l, r;
    for(int i=0 ; i<L ; ++i)
    {
        l = S[i];
        r = S[i+1];

        if(S[i+1] == n)
        {
            cout << 0;
            return 0;
        }

        if(l < n && n < r)
        {
            break;
        }
    }

    int lCnt = n-l-1;
    int rCnt = r-n;

    cout << (lCnt*rCnt) + (rCnt-1);


    return 0;
}