#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

string isPel(int n)
{
    string s = to_string(n);
    int len = s.length();

    for (int i = 0; i < len / 2; ++i)
    {
        if (s[i] != s[len - 1 - i])
        {
            return "no";
        }
    }

    return "yes";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 1;

    while (n > 0)
    {
        cin >> n;
        if(n > 0)
        {
            cout << isPel(n) << "\n";
        }
    }
}