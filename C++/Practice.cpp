#include <iostream>
#include <vector>
using namespace std;
#define ll long long int

vector<ll> lis;
ll *numbers;
ll* newIndexes;

void UpdateLIS(int index)
{
    ll len = lis.size();
    if(len == 0)
    {
        lis.push_back(numbers[index]);
        return;
    }

    ll l = 0;
    ll r = len - 1;

    while(l < r)
    {
        ll mid = (l + r) / 2;
        if(lis[mid] < numbers[index]) l = mid+1;
        else if(lis[mid] > numbers[index]) r = mid;
        else { l = mid; break; }
    }

    if(l == len-1 && lis[l] < numbers[index])
    {
        lis.push_back(numbers[index]);
        newIndexes[index] = len;
        return;
    }

    lis[l] = numbers[index];
    newIndexes[index] = l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll N; cin >> N;
    numbers = new ll[N];
    newIndexes = new ll[N];

    for(int i=0 ; i<N ; ++i)
    {
        cin >> numbers[i];
        UpdateLIS(i);
    }

    ll len = lis.size();
    int answers[len];

    int cnt = len-1;
    for(int i=N-1 ; i>=0 ; --i)
    {
        if(newIndexes[i] == cnt)
        {
            answers[cnt] = numbers[i];
            cnt--;
        }
        if(cnt < 0) break;
    }

    cout << len << "\n";
    for(int i=0 ; i<len ; ++i)
    {
        cout << answers[i] << ' ';
    }

    return 0;
}