#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    cin >> N;
    int k[N];

    for(int i=0 ; i<N ; ++i)
    {
        cin >> k[i];
    }

    sort(k, k+N);

    int requiredCnt = 0;
    int answer = 0;
    for(int i=0 ; i<N ; ++i)
    {
        requiredCnt = k[i];
        if(i >= requiredCnt)
        {
            answer = i+1;
            break;
        }
    }

    cout <<  answer;

    return 0;
}