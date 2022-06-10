#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 2000000002;
#define pq priority_queue<Bus, vector<Bus>, CompareBus>

int N, M, S, E;
struct Bus
{
    int to, cost;
    Bus(int t, int c)
    {
        to = t;
        cost = c;
    }
};
struct CompareBus
{
    bool operator() (Bus& b1, Bus& b2)
    {
        return b1.cost > b2.cost;
    }
};
struct City
{
    int minumumCost = INF; // from start
    pq buses;
};

City* cities;
pq q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    if(N == 1)
    {
        cout << 0;
        return 0;
    }
    cin >> M;
    cities = new City[N];

    for (int i = 0; i < M; ++i)
    {
        int a, b, c; cin >> a >> b >> c; a--; b--;
        cities[a].buses.push(Bus(b, c));
    }

    cin >> S >> E; S--; E--;
    q.push(Bus(S, 0));
    cities[S].minumumCost = 0;

    while(!q.empty())
    {
        Bus bus = q.top(); q.pop();
        City* city = cities + bus.to;

        while(!city->buses.empty())
        {
            Bus nextBus = city->buses.top(); city->buses.pop();
            City* nextCity = cities + nextBus.to;
            int w = city->minumumCost + nextBus.cost;

            if(w >= nextCity->minumumCost) continue;

            nextCity->minumumCost = w;
            q.push(nextBus);
        }
    }

    cout << cities[E].minumumCost;

    return 0;
}