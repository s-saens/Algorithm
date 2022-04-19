#include <iostream>
#include <set>
#include <cmath>

using namespace std;

#define FOR(i, N) for(int i=0 ; i<N ; ++i)

class Number
{
public:
    int value = 0;

    Number(int n) { value = n; }

    bool operator < (const Number &s1) const
    {
        if(abs(s1.value) > abs(this->value)) return true;
        else if(abs(s1.value) == abs(this->value) && s1.value > this->value) return true;
        return false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    multiset<Number> numbers;

    int N; cin >> N;
    FOR(i, N)
    {
        int x; cin >> x;
        if(x == 0)
        {
            if(numbers.empty())
            {
                cout << "0\n";
            }
            else
            {
                cout << numbers.begin()->value << "\n";
                numbers.erase(numbers.begin());
            }
        }
        else
        {
            numbers.insert(Number(x));
        }
    }

    return 0;
}