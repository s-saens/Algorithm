#include <iostream>
#include <algorithm>

using namespace std;

string to_suffix(string e)
{
    string result = "";
    string op = "";
    for(int i=0 ; i<e.length() ; i++)
    {
        switch (e[i])
        {
            case '(':
                op += e[i];
                break;
            case ')':
                while(op.back() != '(')
                {
                    result += op.back();
                    op.pop_back();
                }
                op.pop_back();
                break;
            case '*':
            case '/':
                while(op.length() > 0 && op.back() == '*' || op.back() == '/')
                {
                    result += op.back();
                    op.pop_back();
                }
                op += e[i];
                break;
            case '+':
            case '-':
                while(op.length() > 0 && op.back() != '(')
                {
                    result += op.back();
                    op.pop_back();
                }
                op += e[i];
                break;
            default:
                result += e[i];
                break;
        }
    }
    while(op.length() > 0)
    {
        result += op.back();
        op.pop_back();
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string e; cin >> e;

    cout << to_suffix(e);

    return 0;
}