#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;
    string parenthesis[N];

    for(int i=0 ; i<N ; ++i)
    {
        cin >> parenthesis[i];
    }

    for(int i=0 ; i<N ; ++i)
    {
        int len = parenthesis[i].length();
        int count = 0;
        for(int j=0 ; j<len ; ++j)
        {
            if(parenthesis[i][j] == '(')
            {
                count++;
            }
            else if(parenthesis[i][j] == ')')
            {
                count--;
            }

            if(count < 0)
            {
                break;
            }
        }
        if(count == 0)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }

    return 0;
}