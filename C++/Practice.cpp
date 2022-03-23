#include <iostream>

using namespace std;

int N, M;

void Permutation(int start, int cnt, string s)
{
    if(cnt >= M-1)
    {
        cout << s + to_string(start) << "\n";
        return;
    }

    s += to_string(start) + ' ';

    for(int i=start+1 ; i<=N ; ++i)
    {
        Permutation(i, cnt+1, s);
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    
    for(int i=1 ; i<=N ; ++i)
    {
        Permutation(i, 0, "");
    }

    return 0;
}