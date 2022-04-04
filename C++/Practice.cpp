#include <iostream>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int numbers[N];

    for(int i=0 ; i<N ; ++i)
    {
        cin >> numbers[i];
        if(i>0)
        {
            numbers[i] += numbers[i-1];
        }
    }

    for(int i=0 ; i<M ; ++i)
    {
        int l, r;
        cin >> l >> r; l--; r--;

        int answer = numbers[r];
        if(l>0) answer -= numbers[l-1];
        cout << answer << "\n";
    }

    return 0;
}