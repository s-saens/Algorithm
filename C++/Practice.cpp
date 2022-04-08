#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int> pq;

    int N; cin >> N;
    vector<int> answer;

    for(int i=0 ; i<N ; ++i)
    {
        int num; cin >> num;
        if(num == 0)
        {
            if(pq.empty())
            {
                cout << 0 << "\n";
                continue;
            }
            cout << pq.top() << "\n";
            pq.pop();
        }
        else
        {
            pq.push(num);
        }
    }

    return 0;
}