#include <iostream>
#include <algorithm>

using namespace std;

int DP[31][31]; // DP[x][y] 에 있는 원소는 F(x, y)를 의미함.

int Calc(int x, int y)
{
    if(DP[x][y] != -1)
    {
        return DP[x][y];
    }

    int sum = 0;
    for(int i=y-1 ; i>=x-1 ; --i)
    {
        sum += Calc(x-1,i);
    }

    DP[x][y] = sum;
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for(short i=0 ; i<31 ; ++i)
    {
        for(short j=0 ; j<31 ; ++j)
        {
            if(i == j)
            {
                DP[i][j] = 1;
            }
            else if(i==1)
            {
                DP[i][j] = j;
            }
            else
            {
                DP[i][j] = -1;
            }
        }
    }

    int answers[T];

    for(int i=0 ; i<T ; ++i)
    {
        int x, y;
        cin >> x >> y;
        answers[i] = Calc(x, y);
    }

    for(int i=0; i<T ; ++i)
    {
        cout << answers[i] << "\n";
    }

    return 0;
}