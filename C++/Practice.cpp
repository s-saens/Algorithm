#include <iostream>
#include <algorithm>
#define FOR(i, s, e) for(int i=s ; i<e ; ++i)

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S1, S2;
    cin >> S1 >> S2;

    int l1 = S1.length()+1; // 가로
    int l2 = S2.length()+1; // 세로
    int k[l2][l1];

    FOR(x, 0, l1) k[0][x] = 0;
    FOR(y, 0, l2) k[y][0] = 0;

    int answer = 0;

    FOR(y, 1, l2) FOR(x, 1, l1)
    {
        if(S1[x-1] == S2[y-1]) k[y][x] = k[y-1][x-1] + 1;
        else k[y][x] = max(k[y][x-1], k[y-1][x]);
        answer = max(answer, k[y][x]);
    }

    cout << answer;

    return 0;
}