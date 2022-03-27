#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int N, M;
vector<int> numbers;
vector<string> selected;
map<string, bool> m;

void Combination(int startIndex, int cnt, string s, vector<bool> visited)
{
    s += to_string(numbers[startIndex]);

    if (cnt >= M - 1)
    {
        if(m.count(s) == 0)
        {
            selected.push_back(s);
            m[s] = true;
        }
        return;
    }

    visited[startIndex] = true;

    s += ' ';

    for (int i = 0; i < N; ++i)
    {
        if(!visited[i])
        {
            Combination(i, cnt + 1, s, visited);
        }
    }
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
        numbers.push_back(a);
    }

    sort(numbers.begin(), numbers.end());

    vector<bool> visited;

    for (int i = 0; i < 10; ++i)
    {
        visited.push_back(false);
    }

    for(int i=0 ; i<N ; ++i)
    {
        Combination(i, 0, "", visited);
    }
    
    int i;
    for(i=0 ; i<selected.size()-1 ; ++i)
    {
        if(selected[i].compare(selected[i+1]) != 0) // 다음 이어질 항목이 현재 것과 다를 경우에만 출력.
        {
            cout << selected[i] << "\n";
        }
    }
    cout << selected[i] << "\n"; // 마지막 항목 출력

    return 0;
}