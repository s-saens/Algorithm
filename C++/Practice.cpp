#include <iostream>
#include <queue>
using namespace std;
#define ll long long

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

ll f(int w)
{
    if(w == 1) return 1;
    return 2 * f(w-1) + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    if(N > 20)
    {
        cout << f(N);
        return 0;
    }

    cout << F(N, 1, 3) << '\n';

    while(!st.empty())
    {
        pair<int, int> t = st.front(); st.pop();
        cout << t.first << ' ' << t.second << '\n';
    }

    return 0;
}