#include <iostream>
#include <algorithm>
#define ll long long
#define FOR(i,s,e) for(int i=s ; i<e; ++i)
using namespace std;

string s;

void change(char &c)
{
    if(c >= 'a' && c <= 'z')
    {
        c = (c - 'a' + 13) % 26 + 'a';
    }
    else if (c >= 'A' && c <= 'Z')
    {
        c = (c - 'A' + 13) % 26 + 'A';
    }
}

int main()
{
    getline(cin, s);

    for(auto &c : s)
    {
        change(c);
    }

    cout << s;

    return 0;
}