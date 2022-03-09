#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    int len = s.length();

    string answer = "{";

    for(int i=0 ; i<len-2 ; ++i)
    {
        string newS;
        string fragments[3];
        for(int j=i+1 ; j<len-1 ; ++j)
        {
            // (시작위치, 길이)
            fragments[0] = s.substr(0, i+1);
            reverse(fragments[0].begin(), fragments[0].end());
            fragments[1] = s.substr(i + 1, j - i);
            reverse(fragments[1].begin(), fragments[1].end());
            fragments[2] = s.substr(j + 1, len - j - 1);
            reverse(fragments[2].begin(), fragments[2].end());
            
            newS = fragments[0] + fragments[1] + fragments[2];

            if (answer.compare(newS) > 0)
            {
                answer = newS;
            }
        }

    }

    cout << answer;

    return 0;
}