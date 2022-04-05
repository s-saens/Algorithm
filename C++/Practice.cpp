#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string sik;
    cin >> sik;

    int startIndex = 0;
    int length = 0;

    int answer = 0;
    bool minusAppeared = false;

    int sLen = sik.length();

    for(int i=0 ; i<sLen ; ++i)
    {        
        if(sik[i] == '-' || sik[i] == '+' || i == sLen-1)
        {
            if(i==sLen-1) length++;

            string numberString = sik.substr(startIndex, length);
            int number = stoi(numberString);

            if(minusAppeared)
            {
                answer -= number;
            }
            else
            {
                answer += number;
            }
            startIndex = i+1;
        }

        if (sik[i] == '-')
        {
            minusAppeared = true;
        }

        length++;
    }

    cout << answer;

    return 0;
}