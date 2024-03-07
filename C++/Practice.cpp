#include <iostream>
#include <unordered_set>
#define ll long long
using namespace std;

int main()
{
    unordered_set<ll> set;
    ll a, b, ab;
    cin >> a >> b; ab = a * b;

    for(ll i=1 ; i*a<ab ; ++i) set.insert(i*a);

    for(ll i=1 ; i*b<ab ; ++i)
        if(set.find(i*b) != set.end()) // 없음
        {
            ab = i*b;
            break;
        }

    cout << ab;

    return 0;
}