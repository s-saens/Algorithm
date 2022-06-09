#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i, s, e) for(int i=s;i<e;++i)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    vector<int> s;

    FOR(i, 0, N)
    {
        int a; cin >> a;
        s.push_back(a);
    }

    sort(s.begin(), s.end());

    int len = s.size();
    int M; cin >> M;
    FOR(i, 0, M)
    {
        int k; cin >> k;
        bool hasM = false;

        int l=0, r=len-1, m;
        while(l < r)
        {
            m = (l+r)/2;
            if(s[m] == k) { hasM = true; break;}
            else if(k < s[m]) r = m;
            else l = m+1;
        }

        hasM = hasM || (s[l] == k);
        cout << hasM << ' ';
    }


    return 0;
}