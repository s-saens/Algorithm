#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int E, S, M;
    cin >> E >> S >> M;

    int nowE = 1;
    int nowS = 1;
    int nowM = 1;

    int cnt = 1;
    while(nowE != E || nowS != S || nowM != M)
    {
        cnt++;
        nowE = nowE%15 + 1;
        nowS = nowS%28 + 1;
        nowM = nowM%19 + 1;
    }

    cout << cnt;

    return 0;
}