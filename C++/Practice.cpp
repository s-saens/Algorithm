#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;

void Permutation(int startIndex, int cnt, string s, vector<bool> visited)
{
    if(cnt >= M-1)
    {
        cout << s + to_string(v[startIndex]) << "\n";
        return;
    }

    visited[startIndex] = true;

    s += to_string(v[startIndex]) + ' ';

    for(int i=0 ; i<N ; ++i)
    {
        if(!visited[i])
        {
            Permutation(i, cnt + 1, s, visited);
        }
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
    
    vector<bool> visited;

    for(int i=0 ; i<10 ; ++i)
    {
        visited.push_back(false);
    }

    for(int i=0 ; i<N ; ++i)
    {
        Permutation(i, 0, "", visited);
    }

    return 0;
}