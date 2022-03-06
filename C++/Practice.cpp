#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int minimum = INT_MAX;
    int maximum = 0;

    for(int i=0 ; i<N ; ++i)
    {
        int a;
        cin >> a;
        if(minimum > a) minimum = a;
        if(maximum < a) maximum = a;
    }

    cout << minimum * maximum;
    return 0;
}