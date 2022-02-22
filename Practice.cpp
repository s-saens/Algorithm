#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int number, tmp = 0;

    int lastNumber = 0;
    for(int i=0 ; i<8 ; ++i)
    {
        cin >> number;
        if(lastNumber < number)
        {
            tmp++;
        }
        else
        {
            tmp--;
        }
        lastNumber = number;
    }

    if(tmp >= 8)
    {
        cout << "ascending";
    }
    else if(tmp <= -5)
    {
        cout << "descending";
    }
    else
    {
        cout << "mixed";
    }
}