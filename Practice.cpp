#include <iostream>
#include <cmath>

using namespace std;

long long getCutLANs(long long &cutLength, long long &length)
{
    return length / cutLength;
}

long long MAX(long long &a, long long &b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int K, N;
    cin >> K >> N;

    long long lanLengths[K];

    long long max = 0;
    for(int i=0 ; i<K ; ++i)
    {
        cin >> lanLengths[i];

        max = MAX(max, lanLengths[i]);
    }

    long long left = 1;
    long long right = max;

    long long maxLength = 0;

    while(left <= right)
    {
        long long mid = (right+left)/2;
        long long lansCnt = 0;

        for(int i=0 ; i<K ; ++i)
        {
            lansCnt += getCutLANs(mid, lanLengths[i]);
        }

        if(lansCnt < N) // 자른 후  랜 개수가 모자라면, 더 작게 잘라야 함 : mid 기준 왼쪽 탐색해야 함.
        {
            right = mid-1;
        }
        else
        {
            maxLength = MAX(maxLength, mid);
            left = mid+1;
        }
    }

    cout << maxLength;
}