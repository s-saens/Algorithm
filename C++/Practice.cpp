#include <iostream>
#include <cmath>
#include <algorithm>
#define ll long long int

using namespace std;

struct V2
{
    int x, y;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    V2 p[N+1];
    for(int i=0 ; i<N ; ++i)cin >> p[i].x >> p[i].y;
    p[N] = p[0];

    double sum = 0;
    for(int i=0 ; i<N ; ++i)
    {
        sum += p[i].x * p[i+1].y;
        sum -= p[i+1].x * p[i].y;
        cout << '>' << sum << "\n";
    }
    sum *= 0.5;
    sum = abs(sum);

    printf("%.1f", sum);

    return 0;
}