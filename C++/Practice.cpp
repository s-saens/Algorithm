#include <iostream>
#include <string>

#define ull unsigned long long int

using namespace std;

ull TotalSum(int n)
{
    return (ull)n*(n+1);
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int N = 1;
    int senario = 0;
    while (N>0)
    {
        senario++;
        cin >> N;
        if(N == 0) break;

        string names[N+1];

        string buffer;

        getline(cin, buffer);

        for(int i=0 ; i<N ; ++i)
        {
            getline(cin, names[i]);
        }

        ull sum = 0;
        for(int i=0 ; i<(2*N)-1 ; ++i)
        {
            int number;
            char ab;
            cin >> number >> ab;
            sum += number;
        }

        int lostIndex = TotalSum(N)-sum;

        cout << senario << ' ' << names[lostIndex-1] << endl;
    }

    return 0;
}