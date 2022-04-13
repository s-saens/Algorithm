#include <iostream>
#include <vector>
using namespace std;
#define ll long long int

vector<ll> lis;
ll *numbers;

void UpdateLDS(int index)
{
    ll len = lis.size();
    if (len == 0)
    {
        lis.push_back(numbers[index]);
        return;
    }

    ll l = 0;
    ll r = len - 1;

    while (l < r)
    {
        ll mid = (l + r) / 2;
        if (lis[mid] < numbers[index])
            l = mid + 1;
        else if (lis[mid] > numbers[index])
            r = mid;
        else
        {
            l = mid;
            break;
        }
    }

    if (l == len - 1 && lis[l] < numbers[index])
    {
        lis.push_back(numbers[index]);
        return;
    }

    lis[l] = numbers[index];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll N;
    cin >> N;
    numbers = new ll[N];

    for (int i = 0; i < N; ++i)
    {
        cin >> numbers[i];
    }
    for(int i=N-1 ; i>=0 ; --i)
    {
        UpdateLDS(i);
    }

    ll len = lis.size();

    cout << len;

    return 0;
}