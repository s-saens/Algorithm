#include <iostream>
#include <set>

using namespace std;

#define FOR(i, N) for(int i=0 ; i<N ; ++i)

class Score
{
public:
    int value = 0;
    int index = 0;

    Score() {}
    Score(int v, int i)
    {
        value = v;
        index = i;
    }

    bool operator < (const Score &s1) const
    {
        return s1.value < this->value;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    set<Score> scores;
    set<int> indexes;

    FOR(i, 8)
    {
        int v; cin >> v;
        scores.insert(Score(v, i));
    }

    int sum =0;
    FOR(i, 5)
    {
        Score s = (*scores.begin());
        sum += s.value;
        indexes.insert(s.index);
        scores.erase(scores.begin());
    }
    cout << sum << "\n";

    FOR(i, 5)
    {
        cout << *indexes.begin() + 1 << ' ';
        indexes.erase(indexes.begin());
    }

    return 0;
}