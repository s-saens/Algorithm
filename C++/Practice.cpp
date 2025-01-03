#include <iostream>
#include <algorithm>
#define FOR(i,s,e) for(int i=s ; i<e; ++i)

using namespace std;

int main()
{
    int N; cin >> N;
    string arr[N];

    FOR(i,0,N)
    {
        cin >> arr[i];
    }

    int len = arr[0].length();

    FOR(i,0,len)
    {
        char c = arr[0][i];
        FOR(j,1,N)
        {
            if(arr[j][i] != c)
            {
                c = '?';
                break;
            }
        }
        cout << c;
    }

    return 0;
}