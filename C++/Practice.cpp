#include <iostream>
#include <map>
#define ll unsigned long long

using namespace std;

ll *stairs;
map<pair<int, int>, ll> maxScore;
int stairsCnt;

ll GoUp(int index, int seq)
{
    pair<int, int> p = make_pair(index, seq);
    
    if (maxScore[p] > 0)
    {
        return maxScore[p];
    }

    ll oneStep = 0;
    ll twoStep = 0;

    if(index == stairsCnt-2 && seq >= 1) // 마지막 계단 못밟는 경우(마지막에서 두번째인데 seq가 1 이상인 상태), 0을 return
    {
        return 0;
    }

    if (index < stairsCnt - 1 && seq < 1) // +1 계단 밟을 수 있음
    {
        oneStep = GoUp(index + 1, seq + 1);
    }

    if (index < stairsCnt - 2) // +2 계단 밟을 수 있음
    {
        twoStep = GoUp(index + 2, 0);
    }


    ll sum = stairs[index] + max(oneStep, twoStep);

    maxScore[p] = sum;
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    cin >> N;

    stairsCnt = N;

    ll s[N];

    stairs = s;

    for (int i = 0; i < N; ++i)
    {
        for(int j=0 ; j<3 ; ++j)
        {
            maxScore[make_pair(i, j)] = 0;
        }
        cin >> stairs[i];
    }

    if(N == 1)
    {
        cout << GoUp(0, 0);
        return 0;
    }

    cout << max(GoUp(0, 0), GoUp(1, 0));

    return 0;
}