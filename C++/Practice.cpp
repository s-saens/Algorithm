#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i, s, e) for(int i=s; i<e ; ++i)
#define MAX 20000000

int N;
struct House
{
    int colorCost[3];
};
House *houses;

int minCostDP[4][4][1001]; // startColor, lastColor와 index에 따른 값

void InitMinCostDP()
{
    FOR(k, 0, 4) FOR(i, 0, 4) FOR(j, 0, 1001) minCostDP[k][i][j] = -1;
}

int MinCost(int startColor, int lastColor, int index)
{
    if (index == N) return 0;
    if (minCostDP[startColor][lastColor][index] > -1) return minCostDP[startColor][lastColor][index];



    int minCost = MAX;
    for (int i = 0; i < 3; ++i) // i: thisColor
    {
        if (lastColor == i) continue;
        if (index == N-1 && startColor == i) continue;
        int cost = houses[index].colorCost[i] + MinCost(startColor, i, index + 1);
        minCost = min(minCost, cost);
    }

    minCostDP[startColor][lastColor][index] = minCost;
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

    FOR(i, 0, N) FOR(j, 0, 3) cin >> houses[i].colorCost[j];

    int minimum = MAX;
    FOR(i, 0, 3) minimum = min(minimum, houses[0].colorCost[i] + MinCost(i, i, 1));

    cout << minimum;

    return 0;
}