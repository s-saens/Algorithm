#include <iostream>
#include <algorithm>
#define FOR(i,s,e) for(int i=s ; i<e ; ++i)
using namespace std;

int *num, *sum;

int main()
{
    int N; cin >> N;
    num = new int[N];
    sum = new int[N];

    FOR(i,0,N)
    {
        cin >> num[i];
        sum[i] = num[i];
        if (i > 0) sum[i] += sum[i-1];
    }
    int l=0, r=N-1, m=0, M=0;
    
    while(++m < r)
    {
        // S**S**D
        int a = (sum[m] - num[l] - num[m]) + (sum[r] - sum[m]) * 2;
        // S**D**S
        int b = sum[r] - num[l] - num[r] + num[m];
        // D**S**S
        int c = (sum[r] - sum[m] - num[r]) + (sum[m] - num[m]) * 2;

        M = max(a, M);
        M = max(b, M);
        M = max(c, M);
    }

    cout << M;

    return 0;
}