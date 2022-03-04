#include <iostream>
#include <algorithm>

using namespace std;

int SearchFirstIndex(int* cards, int length, int number)
{
    int l, r, m;
    l = 0;
    r = length-1;
    while(l < r)
    {
        m = (l+r)/2;
        if(cards[m] >= number)
        {
            r = m;
        }
        else
        {
            l = m+1;
        }
    }
    return l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int cards[N];

    for(int i=0 ; i<N ; ++i)
    {
        cin >> cards[i];
    }

    sort(cards, cards+N);

    int M;
    cin >> M;
    int numbers[M];
    int counts[M];

    for(int i=0; i<M ; ++i)
    {
        cin >> numbers[i];
    }

    for(int i=0 ; i<M ; ++i)
    {
        int num = numbers[i];
        int searchIndex = SearchFirstIndex(cards, N, num);
        int cnt = 0;
        for(int j=searchIndex ; j<N ; ++j)
        {
            if(cards[j] == num)
            {
                cnt++;
            }
            else
            {
                break;;
            }
        }
        counts[i] = cnt;
    }

    for(int i=0 ; i<M ; ++i)
    {
        cout << counts[i] << ' ';
    }

    return 0;
}