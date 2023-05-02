#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

#define FOR(i,s,e) for(int i=s ; i<e ; ++i)
#define ll long long
using namespace std;

string input;
int len;
bool bad = false;

ll f(int l, int r)
{
    if (l >= r)
        return 1;

    vector<int> starts;
    vector<int> ends;
    int cnt = 0;

    FOR(i, l, r + 1)
    {
        switch (input[i])
        {
        case '(':
        case '[':
            if (cnt == 0)
                starts.push_back(i);
            cnt++;
            break;
        case ')':
        case ']':
            cnt--;
            if (cnt == 0)
                ends.push_back(i);
            break;
        }
    }

    ll ret = 0;
    int slen = starts.size();

    if (ends.size() != slen)
        return -1;

    FOR(i, 0, slen)
    {
        int s = starts[i], e = ends[i];
        ll k = f(s + 1, e - 1);

        if (k < 0)
            return -1;

        if (input[s] == '(')
            ret += k * 2;
        else if (input[s] == '[')
            ret += k * 3;
        else
            return -1;
    }

    return ret;
}

bool check()
{
    int cnt2 = 0, cnt3 = 0;
    stack<char> s;
    FOR(i, 0, len)
    {
        char c = input[i];
        switch (c)
        {
        case '(':
        case '[':
            s.push(c);
            break;
        case ')':
            if (s.empty() || s.top() != '(')
                return false;
            s.pop();
            break;
        case ']':
            if (s.empty() || s.top() != '[')
                return false;
            s.pop();
            break;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;
    len = input.length();

    if (!check())
    {
        cout << 0;
        return 0;
    }

    int answer = f(0, len - 1);
    if (answer > 0)
        cout << answer;
    else
        cout << 0;

    return 0;
}