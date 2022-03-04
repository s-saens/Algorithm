#include <iostream>
#include <algorithm>

using namespace std;

int SearchFirstIndex(int* cards, int length, int number)
{
    int l, r, m;
    l = 0;
    r = length-1;

    if (cards[l] == number)
    {
        return l;
    }

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

    if(cards[l] != number)
    {
        return -1;
    }
    return l;
}

int SearchLastIndex(int *cards, int length, int number)
{
    int l, r, m;
    l = 0;
    r = length - 1;

    if (cards[r] == number)
    {
        return r;
    }

    while (l < r)
    {
        m = (l + r) / 2;
        if (cards[m] <= number)
        {
            l = m+1;
        }
        else
        {
            r = m;
        }
    }
    if (cards[l-1] != number)
    {
        return -1;
    }
    return l-1;
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
        int firstIndex = SearchFirstIndex(cards, N, num);
        int lastIndex = SearchLastIndex(cards, N, num);

        counts[i] = lastIndex-firstIndex + 1;
        if (firstIndex == -1)
        {
            counts[i]--;
        }
    }

    for(int i=0 ; i<M ; ++i)
    {
        cout << counts[i] << ' ';
    }

    return 0;
}