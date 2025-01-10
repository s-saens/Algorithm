#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N; cin >> N;
    unsigned long long sum = 0;
    int cnt[N], m = 0;

    for(int i=0 ; i<N ; ++i)
    {
        cin >> cnt[i];
        sum += cnt[i];
        m = max(m, cnt[i]);
    }

    string answer = "Happy";

    if(sum/2 < m) answer = "Unhappy";
    if(N == 1 && sum == 1) answer = "Happy";

    cout << answer;

    return 0;
}