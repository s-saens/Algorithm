#include <iostream>
using namespace std;

int main()
{
    string L, R; cin >> L >> R;
    int sl = L.length(), sr = R.length();

    int sum = 0;
    if(sl == sr) for(int i=0 ; i<sl ; ++i)
    {
        int l = sl-1-i;
        if(L[l] == '8' && R[l] == '8') sum++;
        else if(L[l] != R[l]) sum = 0;
    }

    cout << sum;
    return 0;
}