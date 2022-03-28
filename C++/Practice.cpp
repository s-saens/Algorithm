#include <iostream>
#include <algorithm>

using namespace std;

int N;
struct House
{
    int colorCost[3];
};
House* houses;

int minCostDP[4][1001]; // lastColor와 index에 따른 값

void InitMinCostDP()
{
    for(int i=0 ; i<4 ; ++i)
    {
        for(int j=0 ; j<1001 ; ++j)
        {
            minCostDP[i][j] = -1;
        }
    }
}

int MinCost(int lastColor, int index)
{
    if(minCostDP[lastColor][index] > -1)
    {
        return minCostDP[lastColor][index];
    }
    if(index == N )
    {
        return 0;
    }

    int minCost = 20000000;
    int minColor = 0;
    for(int i=0 ; i<3 ; ++i) // i: thisColor
    {
        if(lastColor == i)
        {
            continue;
        }
        int cost = houses[index].colorCost[i] + MinCost(i, index + 1);
        minCost = min(minCost, cost);
    }

    minCostDP[lastColor][index] = minCost;
    return minCost;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    InitMinCostDP();

    cin >> N;
    House h[N];
    houses = h;

    for(int i=0 ; i<N ; ++i)
    {
        for(int j=0 ; j<3 ; ++j)
        {
            cin >> houses[i].colorCost[j];
        }
    }

    cout << MinCost(3, 0);

    return 0;
}