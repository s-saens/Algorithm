#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    if(N == 0 || N == 1)
    {
        cout << N;
        return 0;
    }
    unsigned long long Fib[N+1];
    Fib[0] = 0;
    Fib[1] = 1;
    for(int i=2; i<N+1 ; ++i) Fib[i] = Fib[i-1] + Fib[i-2];

    cout << Fib[N];

    return 0;
}