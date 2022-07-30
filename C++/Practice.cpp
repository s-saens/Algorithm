#include <iostream>
#include <set>
using namespace std;
int main()
{
    int N, score, P;
    cin >> N >> score >> P;

    if(N == 0)
    {
        cout << 1;
        return 0;
    }

    int firstIndex = -2;
    int i = 0;
    for (i = 0; i < P && i < N; ++i)
    {
        int n; cin >> n;
        if(firstIndex < 0)
        {
            if(n < score)
            {
                firstIndex = i;
                break;
            }
            if(n == score)
            {
                firstIndex = i;
            }
        }

        if (n == score)
        {
            if (i == P - 1)
            {
                cout << -1;
                return 0;
            }
        }
    }
    if(firstIndex < 0 && N < P) firstIndex = i;
    cout << firstIndex + 1;
    return 0;
}