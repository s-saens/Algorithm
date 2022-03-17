#include <iostream>
#include <vector>
#define ll long long int
#define MMM 1000000

using namespace std;


vector<ll> primes;

bool isPrime[MMM];

void InitFlags()
{
    for(int i=0 ; i<MMM ; ++i)
    {
        isPrime[i] = true;
    }
}

void SetFlagsAsFalse(int startNumber)
{
    for(int i=startNumber+startNumber ; i<MMM ; i+=startNumber)
    {
        isPrime[i] = false;
    }
}

void SetPrimes()
{
    isPrime[0] = false;
    for(int i=2 ; i<MMM ; ++i)
    {
        if(isPrime[i])
        {
            SetFlagsAsFalse(i);
            primes.push_back(i);
        }
    }
}

string IsValid(ll number)
{
    int len = primes.size();
    for(int i=0 ; i<len ; ++i)
    {
        if(number % primes[i] == 0)
        {
            return "NO";
        }
    }
    return "YES";
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    InitFlags();
    SetPrimes();

    short N;
    cin >> N;

    string answer[N];

    for(int i=0 ; i<N ; ++i)
    {
        ll number;
        cin >> number;
        answer[i] = IsValid(number);
    }

    for(int i=0 ; i<N ; ++i)
    {
        cout << answer[i] << "\n";
    }


    return 0;
}