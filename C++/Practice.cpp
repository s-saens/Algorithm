#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> josephus;
    int people[N];
    bool selected[N];

    for(int i=0 ; i<N ; ++i)
    {
        people[i] = i+1;
        selected[i] = false;
    }

    int lastIndex = 0;

    int cnt = K;
    for (int i = 0; i < N; ++i)
    {
        int cnt = K;
        while(cnt > 0)
        {
            if (!selected[lastIndex])
            {
                cnt--;
            }

            if(cnt > 0)
            {
                lastIndex = (lastIndex + 1) % N;
            }
        }
        josephus.push_back(people[lastIndex]);
        selected[lastIndex] = true;
        lastIndex = (lastIndex + 1) % N;
    }

    string answer = "<";
    cout << '<';
    for(int i=0 ; i<N-1 ; ++i)
    {
        cout << josephus[i] << ", ";
    }
    cout << josephus[N-1] << '>';

    return 0;
}