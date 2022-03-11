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

    int numbers[len];


    for(int i=0 ; i<len ; ++i)
    {
        numbers[i] = (int)s[i]-(int)'0';
    }

    sort(numbers, numbers + len);

    for(int i=len-1 ; i>=0 ; --i)
    {
        cout << numbers[i];
    }


    return 0;
}