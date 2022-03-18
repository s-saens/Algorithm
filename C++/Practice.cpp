#include <iostream>
#include <cmath>
using namespace std;

int pSum[50001];

int GetSetPow(int n)
{
    if(pSum[n] > -1) return pSum[n];

    int rn = (int)sqrt(n);

    int minimum = n;

    for(int i=rn ; i>=1 ; --i)
    {
        minimum = min( 1 + GetSetPow(n - (i * i)), minimum );
    }
    
    pSum[n] = minimum;
    return pSum[n];
}

void InitPow()
{
    for(int i=0 ; i<50001 ; ++i)
    {
        pSum[i] = -1;
    }
    pSum[0] = 0;
    pSum[1] = 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    InitPow();

    int n;
    cin >> n;

    cout << GetSetPow(n);

    return 0;
}