#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    int N; cin >> N;
    queue<int> q;
    stack<int> s;

    int M = 0;

    while(N--) { int n; cin >> n; M = max(M, n); q.push(n); }

    int a = 1;
    while(!q.empty())
    {
        int n = q.front();

        if(n == a)
        {
            q.pop();
            a++;
        }
        else if(!s.empty() && s.top() == a)
        {
            s.pop();
            a++;
        }
        else
        {
            q.pop();
            s.push(n);
        }
    }

    while(!s.empty())
    {
        int n = s.top();
        if(n != a) break;
        s.pop();
        a++;
    }

    cout << (s.empty() ? "Nice" : "Sad");

    return 0;
}