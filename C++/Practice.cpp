#include <iostream>
using namespace std;

int F(int n)
{
    return n%2 ? n/2 : n/2 - 1;
}

int main()
{
    int t = 0;
    while(1)
    {
        t++;
        long long T, cnt = 0;
        cin >> T;
        if(!T) return 0;
        for(int i=T-3 ; i>0 ; i-=3) cnt += F(i);
        cout << "Case #" << t << ": " << T << ':' << cnt << '\n';
    }
}