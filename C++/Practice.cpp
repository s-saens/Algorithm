#include <iostream>
#define FOR(i,s,e) for(int i=s ; i<e; ++i)

using namespace std;

int main()
{
    int l = 0, o = 0, v = 0, e = 0;
    string name; cin >> name;
    FOR(i, 0, name.size())
    {
        switch(name[i])
        {
            case 'L': l++; break;
            case 'O': o++; break;
            case 'V': v++; break;
            case 'E': e++; break;
        }
    }

    int maximum = -1;
    string answer = "";

    int N; cin >> N;
    FOR(i, 0, N)
    {
        int L=l, O=o, V=v, E=e;
        string teamName; cin >> teamName;

        FOR(i, 0, teamName.size())
        {
            switch(teamName[i])
            {
                case 'L': L++; break;
                case 'O': O++; break;
                case 'V': V++; break;
                case 'E': E++; break;
            }
        }

        int k = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;

        if (k > maximum)
        {
            maximum = k;
            answer = teamName;
        }
        else if (k == maximum && answer > teamName)
        {
            answer = teamName;
        }
    }

    cout << answer;
    return 0;
}