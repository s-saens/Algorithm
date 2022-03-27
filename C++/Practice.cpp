#include <iostream>
#include <algorithm>

using namespace std;

int N, K;

struct Thing
{
    int weight = 0;
    int value = 0;
};

Thing* things;

int maxValue[101][100001]; // startIndex와 cnt에 따른 최댓값을 memoization : 두 변수 모두 100 이하임.

void InitMaxValue()
{
    for(int i=0 ; i<101 ; ++i)
    {
        for(int j=0 ; j<100001 ; ++j)
        {
            maxValue[i][j] = -1;
        }
    }
}

int MaxValueSum(int startIndex, int remainWeight)
{
    if (maxValue[startIndex][remainWeight] > -1)
    {
        return maxValue[startIndex][remainWeight];
    }
    if (startIndex >= N)
    {
        return 0;
    }
    if (remainWeight < things[startIndex].weight)
    {
        return 0;
    }

    int sum = 0;
    for(int i=startIndex+1 ; i<N ; ++i)
    {
        sum = max(sum, MaxValueSum(i, remainWeight-things[startIndex].weight));
    }
    sum += things[startIndex].value;

    maxValue[startIndex][remainWeight] = sum;
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    InitMaxValue();

    cin >> N >> K; // N: 물건 개수 // K: 최대 무게

    Thing t[N];
    things = t;

    for(int i=0 ; i<N ; ++i)
    {
        cin >> things[i].weight >> things[i].value;
    }

    int maximum = -1;

    for(int i=0 ; i<N ; ++i)
    {
        maximum = max(maximum, MaxValueSum(i, K));
    }

    cout << maximum;

    return 0;
}