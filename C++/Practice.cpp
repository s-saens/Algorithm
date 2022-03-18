#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    map<string, string> passwords;

    int N, M;
    cin >> N >> M;

    for(int i=0 ; i<N ; ++i)
    {
        string site, pw;
        cin >> site >> pw;
        passwords[site] = pw;
    }

    string answers[M];
    for(int i=0 ; i<M ; ++i)
    {
        string site;
        cin >> site;
        answers[i] = passwords[site];
    }

    for(int i=0 ; i<M ; ++i)
    {
        cout << answers[i] << "\n";
    }
    
    return 0;
}