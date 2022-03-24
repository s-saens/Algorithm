#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;


void Permutation(int startIndex, int cnt, string s)
{
    if(cnt >= M-1)
    {
        cout << s + to_string(v[startIndex]) << "\n";
        return;
    }

    s += to_string(v[startIndex]) + ' ';

    for(int i=startIndex ; i<N ; ++i)
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
    for(int i=0 ; i<N ; ++i)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    
    for(int i=0 ; i<N ; ++i)
    {
        Permutation(i, 0, "");
    }

    return 0;
}