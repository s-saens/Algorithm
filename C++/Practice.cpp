#include <iostream>
#include <algorithm>
#define FOR(i, s, e) for(int i=s ; i<e ; ++i)

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    int numbers[N];
    FOR(i, 0, N) cin >> numbers[i];
    sort(numbers, numbers+N);

    FOR(i, 0, N) cout << numbers[N-1-i] << "\n";


    return 0;
}