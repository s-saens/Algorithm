#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    if(N <= 1)
    {
        cout << 0;
        return 0;
    }
    N--;

    int dasom;
    int votes[N];
    cin >> dasom;

    int cnt = 0;

    for(int i=0 ; i<N ; ++i)
    {
        cin >> votes[i];
    }

    sort(votes, votes+N);

    while(true)
    {
        if(votes[N-1] >= dasom)
        {
            votes[N-1]--;
            dasom++;
            cnt++;
            if(votes[N-2] > votes[N-1] && votes[N-2] >= dasom)
            {
                sort(votes, votes+N);
            }
        }
        else
        {
            break;
        }
    }

    cout << cnt;

    return 0;
}