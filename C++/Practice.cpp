#include <iostream>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

struct Number
{
    int value = 0;
    int index = 0;
};

struct cmp
{
    bool operator()(Number& a, Number& b)
    {
        return (a.value > b.value);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L;
    cin >> N >> L;

    priority_queue< Number, vector<Number>, cmp > q;

    for(int i=0 ; i<N ; ++i)
    {
        Number n;
        cin >> n.value;
        n.index = i;

        q.push(n);

        while(q.top().index <= i - L && !q.empty())
        {
            q.pop();
        }

        cout << q.top().value << "\n";
    }

    return 0;
}