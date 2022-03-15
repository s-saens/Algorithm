#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int GetAnswer(int N, int M)
{
    int pivotIndex = M;
    queue<int> q;
    int arr[N];

    int maximum = 0;

    for(int i=0 ; i<N ; ++i)
    {
        int a;
        cin >> a;

        q.push(a);
        arr[i] = a;
    }
    sort(arr, arr+N);

    int maxIndex = N-1;

    int cnt = 0;
    while(maxIndex >= 0)
    {
        if(arr[maxIndex] <= q.front()) // dequeue
        {
            cnt++;
            if(pivotIndex == 0)
            {
                return cnt;
            }
            q.pop();
            maxIndex--;
        }
        else // 맨 뒤로
        {
            q.push(q.front());
            q.pop();
        }
        pivotIndex = (pivotIndex + q.size() - 1) % q.size();
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    int answer[T];

    for(int i=0 ; i<T ; ++i)
    {
        int N, M;
        cin >> N >> M;

        answer[i] = GetAnswer(N, M);
    }

    for(int i=0 ; i<T ; ++i)
    {
        cout << answer[i] << "\n";
    }

    return 0;
}