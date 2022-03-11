#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int requiredCnt[9];

    for(int i=0 ; i<9 ; ++i)
    {
        requiredCnt[i] = 0;
    }

    string s;
    cin >> s;
    int len = s.length();

    int maxRequireCnt = 0;

    for(int i=0 ; i<len ; ++i)
    {
        if(s[i] == '9')
        {
            requiredCnt[6]++;
        }
        else
        {
            requiredCnt[s[i] - '0']++;
        }
    }
    requiredCnt[6] = (requiredCnt[6] % 2) + requiredCnt[6] / 2;

    for(int i=0 ; i<9 ; ++i)
    {
        maxRequireCnt = max(maxRequireCnt, requiredCnt[i]);
    }

    cout << maxRequireCnt;

    return 0;
}