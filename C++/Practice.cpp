#include <iostream>

using namespace std;

int Fives(int n)
{
    int cnt = 0;
    while(n%5 == 0)
    {
        n /= 5;
        cnt++;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int cnt = 0;
    for(int i=1 ; i<=N ; ++i)
    {
        cnt += Fives(i);
    }

    cout << cnt;
}