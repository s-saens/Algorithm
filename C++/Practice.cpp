#include <iostream>
#include <algorithm>
#define FOR(i,e)for(int i=0;i<e;++i)
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    int numbers[N];
    
    FOR(i, N) cin >> numbers[i];
    sort(numbers, numbers+N);

    int lastR = 1;

    FOR(i, N)
    {
        int nowL = numbers[i];
        if (nowL > lastR) break;
        lastR += numbers[i];
    }
    cout << lastR;
    return 0;
}