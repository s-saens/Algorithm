#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int> > st;

int F(int w, int s, int e)
{
    if (w == 1)
    {
        st.push(make_pair(s, e));
        return 1;
    }

    int r = 6-s-e;
    return F(w-1, s, r) + F(1, s, e) + F(w-1, r, e);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    cout << F(N, 1, 3) << '\n';

    while(!st.empty())
    {
        pair<int, int> t = st.front(); st.pop();
        cout << t.first << ' ' << t.second << '\n';
    }

    return 0;
}