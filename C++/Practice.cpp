#include <iostream>
#include <cmath>
#include <algorithm>
#define FOR(i, s, e) for(int i=s ; i<e ; ++i)
#define ll long long int

using namespace std;

ll minimum = 2147483647;
ll minL = 0;
ll minR = 1;

ll* numbers;

ll Min(ll l, ll r)
{
    ll sum = numbers[l] + numbers[r];
    if(abs(minimum) > abs(sum))
    {
        minimum = sum;
        minL = l;
        minR = r;
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    numbers = new ll[N];

    ll changingIndex = 0;
    FOR(i, 0, N)
    {
        cin >> numbers[i];
        if(i > 0 && numbers[i] * numbers[i-1] <= 0) changingIndex = i; // 부호가 바뀌는 index
    }

    if(N == 2)
    {
        cout << numbers[0] << ' ' << numbers[1];
        return 0;
    }

    ll l = 0;
    ll r = 1;

    if(changingIndex > 1)
    {
        l = changingIndex-2;
        r = changingIndex-1;
        Min(l, r);
    }
    if(changingIndex < N-1)
    {
        l = changingIndex;
        r = changingIndex+1;
        Min(l, r);
    }
    if (changingIndex > 0)
    {
        l = changingIndex-1;
        r = changingIndex;
        Min(l, r);
    }
    Min(0, 1);
    Min(N-2, N-1);

    while(l > 0 || r < N-1)
    {
        int sum = Min(l, r);
        if(sum > 0)
        {
            if(l > 0) l--;
            else if(r < N-1) r++;
        }
        else if(sum < 0)
        {
            if(r < N-1) r++;
            else if(l > 0) l--;
        }
        else break;
    }

    Min(l, r);

    cout << numbers[minL] << ' ' << numbers[minR] ;

    return 0;
}