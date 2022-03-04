#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;
    queue<int> q1;

    for(int i=1; i<=N ; ++i)
    {
        q1.push(i);
    }

    for(bool i=false ; ; i=!i)
    {
        if(q1.size() <= 1)
        {
            break;
        }

        if (i == true)
        {
            q1.push(q1.front());
        }
        q1.pop();
    }

    cout << q1.front();

    return 0;
}