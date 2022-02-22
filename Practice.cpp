#include <iostream>
#include <algorithm>

using namespace std;

int reverseStringToInt(string n)
{
    reverse(n.begin(), n.end());
    return stoi(n);
}

int max(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;

    int c = max(reverseStringToInt(a), reverseStringToInt(b));

    cout << c;
}