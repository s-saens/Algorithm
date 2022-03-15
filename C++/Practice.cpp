#include <iostream>
#include <algorithm>
#define ll long long int

using namespace std;

ll CutLength(int treeHeight, int cuttingLength)
{
    if(treeHeight > cuttingLength)
    {
        return treeHeight - cuttingLength;
    }
    else
    {
        return 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll N, Req;
    cin >> N >> Req;

    ll trees[N];

    for(int i=0 ; i<N ; ++i)
    {
        cin >> trees[i];
    }

    sort(trees, trees+N);

    ll sum = 0;

    ll l = 0;
    ll r = trees[N-1];

    while(l < r)
    {
        sum = 0;

        ll mid = (l+r)/2;

        for(int i=N-1 ; i>=0 ; --i)
        {
            sum += CutLength(trees[i], mid);
            if (sum >= Req)
            {
                break;
            }
        }

        if(sum < Req)
        {
            r = mid;
        }
        else
        {
            l = mid+1;
        }
    }

    cout << l-1;


    return 0;
}