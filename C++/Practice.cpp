#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)
{
    int aLen = a.length();
    int bLen = b.length();

    if(aLen < bLen)
    {
        return true;
    }
    else if(aLen > bLen)
    {
        return false;
    }

    if(a.compare(b) > 0)
    {
        return false;
    }
    else
    {
        return true;
    }

}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;

    cin >> N;

    vector<string> strings;

    for(int i=0 ; i<N ; ++i)
    {
        string s;
        cin >> s;
        if(strings.empty() == false && *find(strings.begin(), strings.end(), s) == s)
        {
            continue;
        }

        strings.push_back(s);
    }

    sort(strings.begin(), strings.end(), cmp);

    for(int i=0 ; i<strings.size() ; ++i)
    {
        cout << strings[i] << "\n";
    }

    return 0;
}