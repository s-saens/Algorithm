#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    while(N > 1)
    {
        int i = 2;
        int s = (int)sqrt(N);
        for (i = 2; i <= s; ++i)
        {
            if(N%i == 0)
            {
                cout << i << "\n";
                N/=i;
                break;
            }
        }
        if(i == s + 1) // 위 for문에서 break되지 않음 : 소수라는 뜻.
        {
            cout << N << "\n";
            N = 1;
            break;
        }
    }

    return 0;
}