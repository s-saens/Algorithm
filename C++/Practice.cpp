#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string s = " ";

    while(true)
    {
        getline(cin, s);
        bool isStrange = false;
        int len = s.length();
        if (len == 1 && s[0] == '.')
        {
            return 0;
        }

        stack<char> brackets;

        for(int i=0 ; i<len ; ++i)
        {
            char c = s[i];
            char lastBracket = '?';
            if (brackets.size() > 0)
            {
                lastBracket = brackets.top();
            }
            if(c == '(' || c == '[')
            {
                brackets.push(c);
            }
            else if(c == ']')
            {
                if (lastBracket == '[')
                {
                    brackets.pop();
                }
                else
                {
                    isStrange = true;
                    break;
                }
            }
            else if(c == ')')
            {
                if (lastBracket == '(')
                {
                    brackets.pop();
                }
                else
                {
                    isStrange = true;
                    break;
                }
            }
        }

        if(isStrange)
        {
            cout << "no" << endl;
            continue;
        }

        if(brackets.size() == 0)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }

    return 0;
}