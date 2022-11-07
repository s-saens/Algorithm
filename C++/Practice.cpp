#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '/' || c == '*');
}
bool isOperator(string s)
{
    return (s == "+" || s == "-" || s == "/" || s == "*");
}
bool isBracket(char c)
{
    return (c == '(' || c == ')');
}
string ctos(char c)
{
    string t = "";
    t += c;
    return t;
}
char stoc(string s)
{
    return s[0];
}

vector<string> separate(const string& line)
{
    vector<string> st;

    string item = "";

    int len = line.size();
    for(int i=0 ; i<len ; ++i)
    {
        char c = line[i];
        if(isOperator(c) || isBracket(c))
        {
            if (item != "") st.push_back(item);
            item = "";

            st.push_back(ctos(c));
        }
        else
        {
            item += c;
            if(i == len-1) st.push_back(item);
        }
    }
    return st;
}

int prec(string op)
{
    if (op == "/" || op == "*") return 2;
    else if (op == "+" || op == "-") return 1;
    else return 0;
}

vector<string> getPostfix(vector<string>& infixVector)
{
    vector<string> ret; // 후위표기식 반환값
    stack<string> st; // 연산자 담는 스택

    int len = infixVector.size();
    for (int i = 0; i < len; ++i)
    {
        string item = infixVector[i];

        // 1. 연산자면, 자기보다 우선순위가 낮은 것을 만나기 직전 까지 pop하면서 출력한다.(즉, 자기보다 우선순위가 같거나 높은 것들만 출력된다.)
        //    그 이후에 자기 자신을 스택에 추가.
        if (isOperator(item))
        {
            while (!st.empty() && prec(item) <= prec(st.top()))
            {
                ret.push_back(st.top());
                st.pop();
            }
            st.push(item);
        }
        // 2. ( 만나면 스택에 추가
        else if (item == "(") st.push(item);
        // 3. ) 만나면, (를 만날때까지 돌리면서 만나는 모든 친구들을 그대로 출력
        else if (item == ")")
        {
            while (st.top() != "(")
            {
                ret.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        // 4. 숫자를 만나면 바로 출력
        else ret.push_back(item);
    }

    // 스택에 남아있는 모든 연산자를 출력
    while (!st.empty())
    {
        ret.push_back(st.top());
        st.pop();
    }

    len = ret.size();
    cout << len << "\n";
    for(int i=0 ; i<len ; ++i) cout <<'('<< ret[i] << ')' << ' ';
    cout << '\n';

    return ret;
}

string calculatePostFix(const string &line)
{
    vector<string> infixVector = separate(line);
    vector<string> postfixVector = getPostfix(infixVector);
    
    stack<float> st;

    int len = postfixVector.size();
    for(int i=0 ; i<len ; ++i)
    {
        string item = postfixVector[i];
        if(isOperator(item))
        {
            float n1 = st.top(); st.pop();
            float n2 = 0;
            if(!st.empty())
            {
                n2 = st.top();
                st.pop();
            }
            cout << n1 << '\t' << n2 << '\n';

            float value;
            if(item == "+") value = n2 + n1;
            if(item == "-") value = n2 - n1;
            if(item == "/") value = n2 / n1;
            if(item == "*") value = n2 * n1;
            st.push(value);
        }
        else st.push(stof(item));
    }
    
    return to_string(st.top());
}

int main()
{
    string exp = "+/3";

    cout << calculatePostFix(exp);
    return 0;
}