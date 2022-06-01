#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define FOR(i,s,e) for(int i=s; i<e; ++i)
#define ll long long int

int N;
vector<int> primes;

const int MAX = 4000000;
bool visited[MAX+1];

int l, r, cnt;
ll sum=2;
void L()
{
    sum -= primes[l];
    l++;
}
void R()
{
    r++;
    sum += primes[r];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    memset(visited, 0, sizeof(visited));

    visited[0] = 1;
    visited[1] = 1;
    visited[2] = 0;
    visited[3] = 0;

    FOR(i, 2, MAX)
    {
        if(!visited[i])
        {
            visited[i] = 1;
            primes.push_back(i);
            for(int j=i+i ; j<=MAX ; j += i) visited[j] = 1;
        }
    }

    int s = primes.size();

    l = 0;
    r = 0;
    cnt = 0;

    while(r < s && l <= r)
    {
        if(sum == N) { cnt++; R(); }
        else if(sum < N)
        {
            if(r < s-1) R();
            else L();
        }
        else if(sum > N) L();
    }

    cout << cnt;
    
}