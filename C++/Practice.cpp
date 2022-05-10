#include <iostream>
#include <cmath>
#include <algorithm>
#define ll long long int
#define FOR(i, s, e) for (int i = s; i < e; ++i)
#define MAX 214748364700

using namespace std;

ll minimum = MAX;
ll minL = 0;
ll minC = 1;
ll minR = 2;

ll *numbers;

ll Min(ll l, ll c, ll r)
{
    ll sum = numbers[l] + numbers[r] + numbers[c];
    if (abs(minimum) > abs(sum))
    {
        minimum = sum;
        minL = l;
        minC = c;
        minR = r;
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    numbers = new ll[N];

    FOR(i, 0, N) cin >> numbers[i];

    sort(numbers, numbers+N);

    if (N == 3)
    {
        cout << numbers[0] << ' ' << numbers[1] << ' ' << numbers[2];
        return 0;
    }

    FOR(i, 1, N-1)
    {
        ll c = i;
        ll l = i-1;
        ll r = i+1;
        while (l > 0 || r < N - 1)
        {
            int sum = Min(l, c, r);
            if (sum > 0)
            {
                if (l > 0) l--;
                else if (r < N - 1) r++;
            }
            else if (sum < 0)
            {
                if (r < N - 1) r++;
                else if (l > 0) l--;
            }
            else break;
        }
        Min(l, c, r);
    }

    ll answers[3] = {numbers[minL], numbers[minC], numbers[minR]};
    sort(answers, answers+3);

    FOR(i, 0, 3) cout << answers[i] << ' ';

    return 0;
}