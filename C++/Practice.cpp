#include <iostream>
#include <queue>
#include <set>
#define FOR(i,s,e) for(int i=s;i<e;++i)
using namespace std;

short d[4] = {-1, 1, -3, 3};

struct Snapshot
{
    string snapshot;
    short index = -1;
    short lastDir = -1;
    int cnt = 0;
    Snapshot(string s, short i, short l, int c){snapshot = s;index = i;lastDir = l;cnt = c;}
};


string Swap(string _s, short i1, short i2)
{
    string s = _s;
    char temp = s[i1];
    s[i1] = s[i2];
    s[i2] = temp;
    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string input = "123456780";
    string answer = "123456780";
    set<string> visitedStrings;

    short zeroIndex = -1;
    FOR(i,0,9)
    {
        cin >> input[i];
        if(input[i] == '0') zeroIndex = i;
    }

    queue<Snapshot> q;
    Snapshot fs = Snapshot(input, zeroIndex, -1, 0);

    q.push(fs);

    bool found = false;
    while(!q.empty())
    {
        Snapshot s = q.front(); q.pop();
        if(s.snapshot == answer)
        {
            cout << s.cnt;
            return 0;
        }
        FOR(i,0,4)
        {
            int ni = s.index + d[i];
            if(ni<0 || ni>=9 || d[i] * (ni % 3 - s.index % 3) < 0) continue;
            if(s.lastDir > 0)
            {
                short m = d[ni] * d[s.lastDir];
                if (m == -1 || m == -9) continue;
            }
            string sw = Swap(s.snapshot, s.index, ni);
            if (visitedStrings.find(sw) != visitedStrings.end()) continue;
            
            visitedStrings.insert(sw);
            q.push(Snapshot(sw, ni, i, s.cnt + 1));
        }
    }

    cout << -1;

    return 0;
}