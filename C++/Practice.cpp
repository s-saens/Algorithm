#include <iostream>
#include <unordered_set>
#define FOR(i,s,e) for(int i=s ; i<e ; ++i)
using namespace std;

// i의 부모노드는 i/2
int main()
{
    int T; cin >> T;
    
    while (T--)
    {
        unordered_set<int> s;

        int a, b; cin >> a >> b;

        while(a > 0)
        {
            s.insert(a);
            a /= 2;
        }

        while (b > 0)
        {
            if(s.count(b) > 0)
            {
                cout << b * 10 << '\n';
                break;
            }
            b /= 2;
        }
    }
    return 0;
}