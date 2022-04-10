#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    for(int t=0 ; t<T ; ++t)
    {
        int N; cin >> N;
        
        multiset<int> dpq;

        for(int i=0 ; i<N ; ++i)
        {
            char op; int num;
            cin >> op >> num;
            if (op == 'I') dpq.insert(num);
            else if (op == 'D' && !dpq.empty())
            {
                if(num == 1) dpq.erase(--dpq.end());
                if(num == -1) dpq.erase(dpq.begin());
            }
        }

        if(dpq.empty()) cout << "EMPTY\n";
        else cout << *(--dpq.end()) << ' ' << *dpq.begin() << "\n";
    }

    return 0;
}