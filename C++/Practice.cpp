#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    map<string, int> names;
    vector<string> dbj;

    int N, M;
    cin >> N >> M;

    int cnt = 0;

    for(int i=0 ; i<N ; ++i)
    {
        string n;
        cin >> n;
        if(names.count(n) == 0)
        {
            names[n] = 1;
        }
    }
    for(int i=0 ; i<M ; ++i)
    {
        string n;
        cin >> n;
        if(names.count(n) == 1)
        {
            dbj.push_back(n);
            cnt++;
        }
    }


    sort(dbj.begin(), dbj.end());

    cout << cnt << "\n";
    for(int i=0 ; i<cnt ; ++i)
    {
        cout << dbj[i] << "\n";
    }

    return 0;
}