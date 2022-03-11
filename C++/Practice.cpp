#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    string s;
    cin >> s;
    int len = s.length();

    int area0Cnt = s[0] == '0';
    int area1Cnt = s[0] == '1';

    for(int i=1 ; i<len ; ++i)
    {
        if(s[i-1] != s[i])
        {
            if(s[i] == '0') area0Cnt++;
            if(s[i] == '1') area1Cnt++;
        }
    }

    cout << min(area0Cnt, area1Cnt);

    return 0;
}