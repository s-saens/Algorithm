#include <iostream>
#define FOR(i, s, e) for(int i=s ; i<e ; ++i)

using namespace std;

short result[1001]; // SK가 이기면 1, 아니면 2

void Init()
{
    FOR(i, 0, 1001)
    {
        result[i] = 0;
    }
}

bool Solve(int N, bool skTurn)
{
    if(result[N] > 0) return result[N] == 1;
    bool nextTurn = !skTurn;

    // 기저
    if(N == 1 || N == 3) return skTurn;
    if(N == 2) return !skTurn;

    bool answer = (Solve(N - 1, !skTurn) || Solve(N - 3, !skTurn));
    if(answer) result[N] = 1;
    else result[N] = 2;
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    bool answer = Solve(N, true);
    cout << (answer ? "SK" : "CY");

    return 0;
}