#include <iostream>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long fibo[50];
    fibo[0] = 0;
    fibo[1] = 1;
    fibo[2] = 1;
    fibo[3] = 2;
    for(int i=4 ; i<50 ; ++i)
    {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    int T;

    cin >> T;

    int N[T];

    for(int i=0 ; i<T ; ++i)
    {
        cin >> N[i];
    }
    for(int i=0 ; i<T ; ++i)
    {
        switch (N[i])
        {
        case 0:
            cout << 1 << " " << 0 << "\n";
            break;
        case 1:
            cout << 0 << " " << 1 << "\n";
            break;
        case 2:
            cout << 1 << " " << 1 << "\n";
            break;
        case 3:
            cout << 1 << " " << 2 << "\n";
            break;

        default:
            cout << fibo[N[i]-1] << " " << fibo[N[i]] << "\n";
            break;
        }
    }
}