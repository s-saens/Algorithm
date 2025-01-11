#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#define D(a, b) m.insert({a,b});
#define FOR(i,s,e) for(int i=s ; i<e ; ++i)
using namespace std;


int main()
{
    map<char, char> m;

    D('1','`')D('2','1')D('3','2')D('4','3')D('5','4')D('6','5')D('7','6')D('8','7')D('9','8')D('0','9')D('-','0')D('=','-')
    D('W','Q')D('E','W')D('R','E')D('T','R')D('Y','T')D('U','Y')D('I','U')D('O','I')D('P','O')D('[','P')D(']','[')D('\\',']')
    D('S','A')D('D','S')D('F','D')D('G','F')D('H','G')D('J','H')D('K','J')D('L','K')D(';','L')D('\'',';')
    D('X','Z')D('C','X')D('V','C')D('B','V')D('N','B')D('M','N')D(',','M')D('.',',')D('/','.')
    D(' ', ' ')

    string s;
    vector<string> answers;

    while(getline(cin, s))
    {
        string k;
        FOR(i,0,s.length())
        {
            s[i] = m[s[i]];
            k += s[i];
        }

        answers.push_back(k);
    }

    FOR(i,0,answers.size())
    {
        cout << answers[i] << '\n';
    }

    return 0;
}