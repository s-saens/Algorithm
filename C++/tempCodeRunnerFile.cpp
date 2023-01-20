#include <iostream>
#include <cmath>
#include <algorithm>
#define FOR(i,s,e) for(int i=s ; i<e ; ++i)
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    ll numbers[N];
    int zeroCnt = 0;

    FOR(i, 0, N)
    {
        cin >> numbers[i];
        if(numbers[i] == 0) zeroCnt++;
    }
    sort(numbers, numbers+N);

    int j = 0;
    int borderIndex = 0;

    while(j < N-1 && numbers[j] < 0 && numbers[j+1] < 0)
    {
        numbers[j+1] *= numbers[j];
        numbers[j] = 0;
        borderIndex = j+1;
        j+=2;
    }

    j = N-1;
    while(j > borderIndex+1 && numbers[j] > 1 && numbers[j-1] > 1)
    {
        numbers[j-1] *= numbers[j];
        numbers[j] = 0;
        j-=2;
    }

    ll sum = 0;
    FOR(i, 0, N)
    {
        // 음수끼리 못 곱해지고 남았는데 0도 있는 경우, 0과 곱하기.
        if(numbers[i] < 0 && zeroCnt > 0)
        {
            numbers[i] = 0;
            zeroCnt--;
        }
        sum += numbers[i];
    }

    cout << sum;

    return 0;
}