#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int jose[N];
    int peop[N];

    for(int i=0 ; i<N ; ++i)
    {
        peop[i] = i+1;
        jose[i] = -1;
    }

    int lastIndex = -1;
    for(int i=0 ; i<N ; ++i)
    {
        int remainMove = K;

        while(remainMove>0)
        {
            lastIndex = (lastIndex + 1) % N;
            if (peop[lastIndex] == -1)
            {
                remainMove++;
            }
            remainMove--;
        }
        jose[i] = peop[lastIndex];
        peop[lastIndex] = -1;
    }

    cout << '<';
    for(int i=0 ; i<N ; ++i)
    {
        cout << jose[i];
        if(i < N-1)
        {
            cout << ", ";
        }
    }
    cout << '>';


    return 0;
}