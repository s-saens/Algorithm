#include <iostream>
#include <cmath>
using namespace std;
#define ll long long int


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll A, B;
    cin >> A >> B;

    ll answer;
    if(A > B)
    {
        answer = A - B;
    }
    else
    {
        answer = B - A;
    }

    cout << answer;
    return 0;
}